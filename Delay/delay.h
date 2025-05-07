/*
 * delay.h
 *
 * Created: 4/26/2025 7:56:09 PM
 *  Author: Mohamed-Galal
 */ 

#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>  // Include the AVR delay functions

/*
 * Function Name: delay_ms_custom
 * Description:   Custom millisecond delay function using microseconds.
 */
void delay_ms_custom(uint16_t ms);

#endif
