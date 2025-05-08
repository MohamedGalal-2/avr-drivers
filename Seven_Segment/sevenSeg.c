#define F_CPU 8000000
#include <util/delay.h>
#include "sevenSeg.h"
#include "DIO.h"

// Segment patterns for 0–9, A–F (Common Cathode)
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

// Segment patterns using bcd for 0–9, A–F (Common Cathode)
static const uint8_t bcd_seg_digits[16] = {
	0b0000, // 0
	0b0001, // 1
	0b0010, // 2
	0b0011, // 3
	0b0100, // 4
	0b0101, // 5
	0b0110, // 6
	0b0111, // 7
	0b1000, // 8
	0b1001, // 9
	0b1010, // A
	0b1011, // b
	0b1100, // C
	0b1101, // d
	0b1110, // E
	0b1111  // F
};

void SEG_init(const SevenSeg_t* seg) {
	// Initialize segment pins
	for (uint8_t i = 0; i < 8; i++) {
		DIO_vsetPINDir(seg->seg_ports[i], seg->seg_pins[i], OUTPUT);
	}

	// Initialize common pin
	DIO_vsetPINDir(seg->comm_port, seg->comm_pin, OUTPUT);

	// Show 0 on the display
	SEG_display_digit(seg, 0, MODE_DECIMAL);
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

void SEG_display_two_digit(const SevenSeg_t* seg1, const SevenSeg_t* seg2, uint8_t number, SegMode_t mode)
{
	uint8_t digit1 = number % 10;  // Right digit (units)
	uint8_t digit2 = number / 10;  // Left digit  (tens)

	// === Turn off both displays first ===
	DIO_write(seg1->comm_port, seg1->comm_pin, seg1->type == COMMON_CATHODE ? LOW : HIGH);
	DIO_write(seg2->comm_port, seg2->comm_pin, seg2->type == COMMON_CATHODE ? LOW : HIGH);

	// === Display left digit (tens) ===
	SEG_display_digit(seg1, digit1, mode);
	DIO_write(seg1->comm_port, seg1->comm_pin, seg1->type == COMMON_CATHODE ? HIGH : LOW); // Enable
	_delay_ms(1);
	DIO_write(seg1->comm_port, seg1->comm_pin, seg1->type == COMMON_CATHODE ? LOW : HIGH); // Disable

	// Clear segments after left digit
	for (uint8_t i = 0; i < 8; i++) {
		DIO_write(seg1->seg_ports[i], seg1->seg_pins[i], seg1->type == COMMON_CATHODE ? LOW : HIGH);
	}

	// === Display right digit (units) ===
	SEG_display_digit(seg2, digit2, mode);
	DIO_write(seg2->comm_port, seg2->comm_pin, seg2->type == COMMON_CATHODE ? HIGH : LOW); // Enable
	_delay_ms(1);
	DIO_write(seg2->comm_port, seg2->comm_pin, seg2->type == COMMON_CATHODE ? LOW : HIGH); // Disable

	// Clear segments after right digit
	for (uint8_t i = 0; i < 8; i++) {
		DIO_write(seg2->seg_ports[i], seg2->seg_pins[i], seg2->type == COMMON_CATHODE ? LOW : HIGH);
	}
}

void BCDSEG_init(const BCDSevenSeg_t* seg) {
	// Set the direction of the 4 BCD input pins as output
	for (uint8_t i = 0; i < 4; i++) {
		DIO_vsetPINDir(seg->bcd_ports[i], seg->bcd_pins[i], OUTPUT);
	}

	// Clear all inputs initially (showing 0)
	for (uint8_t i = 0; i < 4; i++) {
		DIO_write(seg->bcd_ports[i], seg->bcd_pins[i], LOW);
	}
}

void BCDSEG_display_digit(const BCDSevenSeg_t* seg, uint8_t digit, SegMode_t mode){
	if ((mode == MODE_DECIMAL && digit > 9) || digit > 15) return;

	uint8_t pattern = bcd_seg_digits[digit];

	for (uint8_t i = 0; i < 4; i++) {
		uint8_t bit_val = (pattern >> i) & 1;
		DIO_write(seg->bcd_ports[i], seg->bcd_pins[i], bit_val);
	}
}




