/*
 * button.h
 *
 * Created: 5/7/2025 11:53:25 AM
 *  Author: Mohamed-Galal
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO.h"

/*
Function Name        : button_vInit
Function Returns     : void
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : define the given pin in the given port as input pin
*/

void button_vInit(unsigned char portname,unsigned char pinnumber);
/*
Function Name        : button_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/

unsigned char button_u8read(unsigned char portname,unsigned char pinnumber);

#endif /* BUTTON_H_ */