/*
 * delay.h
 *
 * Created: 4/29/2025 7:56:09 PM
 *  Author: Mohamed-Galal
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include "keypad_config.h"

/*
Function Name        : keypad_vInit
Function Returns     : void
Function Arguments   : void
Function Description : initialize the keypad.
*/
void keypad_vInit(void);
/*
Function Name        : keypad_u8check_press
Function Returns     : char
Function Arguments   : void
Function Description : return the address of the pressed key.
*/
char keypad_u8check_press(void);

#endif /* KEYPAD_H_ */
