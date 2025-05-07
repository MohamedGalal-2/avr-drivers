/*
 * BUZZER.c
 *
 * Created: 5/6/2025 9:41:29 PM
 *  Author: Mohamed-Galal
 */ 

#include "DIO.h"
#include "delay.h"

void BUZZER_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,OUTPUT); //Set the given pin in the given port as an output
}

void BUZZER_vTurnOn(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,HIGH); //Set the given pin in the given port to one(on)
}

void BUZZER_vTurnOff(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,LOW); //Set the given pin in the given port to zero(off)
}

void BUZZER_vToggle(unsigned char portname,unsigned char pinnumber)
{
	DIO_toggle(portname,pinnumber); //Set the given pin in the given port to zero if it is one or set it to one if it is zero
}

void BUZZER_vBlink(unsigned char portname, unsigned char pinnumber, unsigned int delay_ms)
{
	BUZZER_vTurnOn(portname, pinnumber);
	delay_ms_custom(delay_ms);
	BUZZER_vTurnOff(portname, pinnumber);
	delay_ms_custom(delay_ms);
}

