/*
 * LED.c
 *
 * Created: 5/6/2025 9:41:29 PM
 *  Author: Mohamed-Galal
 */

#include "DIO.h"
#include "delay.h"

void LED_vInit(unsigned char portname, unsigned char pinnumber)
{
    DIO_vsetPINDir(portname, pinnumber, OUTPUT);
}

void LED_vTurnOn(unsigned char portname, unsigned char pinnumber)
{
    DIO_write(portname, pinnumber, HIGH);
}

void LED_vTurnOff(unsigned char portname, unsigned char pinnumber)
{
    DIO_write(portname, pinnumber, LOW);
}

void LED_vToggle(unsigned char portname, unsigned char pinnumber)
{
    DIO_toggle(portname, pinnumber);
}

void LED_vBlink(unsigned char portname, unsigned char pinnumber, unsigned int delay_ms)
{
    LED_vTurnOn(portname, pinnumber);
    delay_ms_custom(delay_ms);
    LED_vTurnOff(portname, pinnumber);
    delay_ms_custom(delay_ms);
}
