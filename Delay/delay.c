/*
 * delay.c
 *
 * Created: 4/26/2025 7:55:56 PM
 *  Author: Mohamed-Galal
 */ 

#include "delay.h"


void delay_ms_custom(uint16_t ms)
{
    while (ms--) {
        // Add a delay for 1 millisecond by calling _delay_us in a loop
        for (uint16_t i = 0; i < 1000; i++) {
            _delay_us(1);  // Delay for 1 microsecond (adjust as needed)
        }
    }
}
