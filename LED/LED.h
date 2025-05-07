/*
 * LED.h
 *
 * Created: 5/6/2025
 * Author: Mohamed Galal
 *
 * Description: Header file for controlling LEDs using packed pin macros.
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

/*
	Function Name        : LED_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_vInit(unsigned char portname, unsigned char pinnumber);

/*
	Function Name        : LED_vTurnOn
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn on the led connected to the given pin and port.
*/
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber);

/*
	Function Name        : LED_vTurnOff
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn off the led connected to the given pin and port.
*/
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber);

/*
	Function Name        : LED_vToggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_vToggle(unsigned char portname, unsigned char pinnumber);

/*
	Function Name        : LED_vBlink
	Function Returns     : void
	Function Arguments   : unsigned char portname, unsigned char pinnumber, unsigned int delay_ms
	Function Description : Turns the LED on, waits for the specified delay in milliseconds, then turns it off and waits again.
	                       This creates a visible blink effect. Requires a delay function (e.g., _delay_ms from <util/delay.h>).
*/
void LED_vBlink(unsigned char portname, unsigned char pinnumber, unsigned int delay_ms); 

#endif /* LED_H_ */
