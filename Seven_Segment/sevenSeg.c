#include "sevenSeg.h"
#include "DIO.h"

// Segment patterns for 0–9, A–F (Common Anode)
static const uint8_t seg_digits[16] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0b01110111, // A
	0b01111100, // b
	0b00111001, // C
	0b01011110, // d
	0b01111001, // E
	0b01110001  // F
};

void SEG_init(const SevenSeg_t* seg) {
	// Initialize segment pins
	for (uint8_t i = 0; i < 8; i++) {
		DIO_vsetPINDir(seg->seg_ports[i], seg->seg_pins[i], OUTPUT);
	}
	// Initialize common pin
	DIO_vsetPINDir(seg->comm_port, seg->comm_pin, OUTPUT);
}

void SEG_display_digit(const SevenSeg_t* seg, uint8_t digit, SegMode_t mode) {
	if ((mode == MODE_DECIMAL && digit > 9) || digit > 15) return;

	uint8_t pattern = seg_digits[digit];

	// Adjust pattern and common pin for display type
	if (seg->type == COMMON_ANODE) {
		pattern = ~pattern;
		DIO_write(seg->comm_port, seg->comm_pin, LOW);  // Enable digit
		} else {
		DIO_write(seg->comm_port, seg->comm_pin, HIGH); // Enable digit
	}

	for (uint8_t i = 0; i < 8; i++) {
		uint8_t bit_val = (pattern >> i) & 1;
		DIO_write(seg->seg_ports[i], seg->seg_pins[i], bit_val);
	}
}

