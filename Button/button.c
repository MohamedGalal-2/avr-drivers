/*
 * button.c
 *
 * Created: 5/7/2025 11:53:15 AM
 *  Author: Mohamed-Galal
 */ 

#include "button.h"

void button_vInit(unsigned char portname, unsigned char pinnumber)
{
	DIO_enable_pullup(portname, pinnumber);  // Set as input and enable pull-up
}

unsigned char button_u8read(unsigned char portname, unsigned char pinnumber)
{
	return DIO_u8read(portname, pinnumber);  // Return the logic level (0 if pressed in active-low config)
}
