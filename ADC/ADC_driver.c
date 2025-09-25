/*
 * ADC_driver.c
 *
 * Created: 9/22/2025 9:41:29 PM
 *  Author: Mohamed-Galal
 */

#include <avr/io.h>
#include <stdint.h>
#include "std_macros.h"

void ADC_vinit(void)
{
	// Vref = AVCC, right-adjust result
	SET_BIT(ADMUX, REFS0);  // REFS1=0, REFS0=1
	
	// Enable ADC
	SET_BIT(ADCSRA, ADEN);
	
	// Prescaler = 128 ? 125 kHz @ 16 MHz (good for 10-bit)
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	//SET_BIT(ADCSRA, ADPS0);
	
	// Dummy conversion to stabilize
	SET_BIT(ADCSRA, ADSC);
	while (!READ_BIT(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);   // clear flag
}

void ADC_selectChannel(uint8_t ch)
{
	ch &= 0x07;                  // ADC0..ADC7
	ADMUX = (ADMUX & 0xE0) | ch; // keep REFS/ADLAR, set MUX4..0
}

uint16_t ADC_u16Read(void)
{
	unsigned short read_val;
	
	SET_BIT(ADCSRA,ADSC);
	while(!READ_BIT(ADCSRA,ADIF)); //stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF flag
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}