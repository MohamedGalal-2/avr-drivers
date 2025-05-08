/*
 * sevenSeg.h
 *
 * Created: 5/7/2025 9:35:18 PM
 *  Author: Mohamed-Galal
 */ 

#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#include <stdint.h>

typedef enum {
	COMMON_CATHODE,
	COMMON_ANODE
} SEG_Type;

typedef enum {
	MODE_DECIMAL,
	MODE_HEXA
} SegMode_t;

typedef struct {
	char seg_ports[8];     // Segment pins A-G, DP
	uint8_t seg_pins[8];

	char comm_port;        // Common pin port (e.g., 'C')
	uint8_t comm_pin;      // Common pin number (e.g., 6)

	SEG_Type type;         // COMMON_ANODE or COMMON_CATHODE
} SevenSeg_t;

/**
 * Initializes the 7-segment display, including segment pins and common pin.
 */
void SEG_init(const SevenSeg_t* seg);

/**
 * Displays a digit (0–9 for decimal, 0–F for hex) on the 7-segment.
 */
void SEG_display_digit(const SevenSeg_t* seg, uint8_t digit, SegMode_t mode);


void SEG_display_two_digit(const SevenSeg_t* seg1, const SevenSeg_t* seg2, uint8_t number, SegMode_t mode);

#endif /* SEVENSEG_H_ */

