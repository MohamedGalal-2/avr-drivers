/*
 * delay.c
 *
 * Created: 4/29/2025 7:55:56 PM
 *  Author: Mohamed-Galal
 */ 

#include <avr/io.h>
#include "std_macros.h"
#include "EEPROM.h"


void EEPROM_write(unsigned short address, unsigned char data)
{
	/* Set up address register*/
	EEARL = (char) address;
	EEARH = (char) (address >> 8);
	
	/* Set up data register */
	EEDR = data;
	
	/* Write logical one to EEMWE*/
	SET_BIT(EECR, EEMWE);
	
	/* Start EEPROM write by setting EEWE*/
	SET_BIT(EECR, EEWE);
	
	/* wait for completion of write operation*/
	while(READ_BIT(EECR,EEWE) == 1);
}

unsigned char EEPROM_read(unsigned short address)
{
	/* Set up address register*/
	EEARL = (char) address;
	EEARH = (char) (address >> 8);
	
	/* Write logical one to EERE*/
	SET_BIT(EECR, EERE);
	
	/* Return data from data register*/
	return EEDR;
}