/*
 * BUZZER.h
 *
 * Created: 5/6/2025 9:41:46 PM
 * Author : Mohamed-Galal
 */

#ifndef BUZZER_H_
#define BUZZER_H_

/*
    Function Name        : BUZZER_vInit
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber
    Function Description : Initializes the pin as an output pin to connect the buzzer.
*/
void BUZZER_vInit(unsigned char portname, unsigned char pinnumber);

/*
    Function Name        : BUZZER_vTurnOn
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber
    Function Description : Turns on the buzzer connected to the given pin and port.
*/
void BUZZER_vTurnOn(unsigned char portname, unsigned char pinnumber);

/*
    Function Name        : BUZZER_vTurnOff
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber
    Function Description : Turns off the buzzer connected to the given pin and port.
*/
void BUZZER_vTurnOff(unsigned char portname, unsigned char pinnumber);

/*
    Function Name        : BUZZER_vToggle
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber
    Function Description : Toggles the state of the buzzer connected to the given pin and port.
*/
void BUZZER_vToggle(unsigned char portname, unsigned char pinnumber);

/*
    Function Name        : BUZZER_vBlink
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber, unsigned int delay_ms
    Function Description : Turns the buzzer on, waits for the specified delay in milliseconds,
                           then turns it off and waits again. Creates a beep effect.
                           Requires a delay function (e.g., _delay_ms from <util/delay.h>).
*/
void BUZZER_vBlink(unsigned char portname, unsigned char pinnumber, unsigned int delay_ms);

#endif /* BUZZER_H_ */
