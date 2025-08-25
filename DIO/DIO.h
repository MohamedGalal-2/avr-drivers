/*
 * DIO.h
 *
 * Created: 4/26/2025 7:56:09 PM
 *  Author: Mohamed-Galal
 */ 

#ifndef DIO_H_
#define DIO_H_

#define HIGH    1
#define LOW     0
#define OUTPUT  1
#define INPUT   0 
#define ENABLE  1
#define DISABLE 0

/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction);

/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue);

/*
	Function Name        : DIO_u8read
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low.
*/
unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_toggle(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : DIO_set_port_direction
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char direction
	Function Description : set the direction of whole port.
*/

void DIO_set_port_direction(unsigned char portname,unsigned char direction);

/*
	Function Name        : DIO_write_port
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char portvalue
	Function Description : Write the value to all port pins.
*/
void DIO_write_port(unsigned char portname,unsigned char portvalue);

/*
	Function Name        : DIO_read_port
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname
	Function Description : read the value of the port.
*/
unsigned char DIO_read_port(unsigned char portname);

/*
	Function Name        : DIO_toggle_port
	Function Returns     : void
	Function Arguments   : unsigned char portname
	Function Description : Reverse the value of the given port.
*/
void DIO_toggle_port(unsigned char portname);

/*
    Function Name        : DIO_enable_pullup
    Function Returns     : void
    Function Arguments   : unsigned char portname, unsigned char pinnumber
    Function Description : Enables the internal pull-up resistor on the specified input pin.
*/
void DIO_enable_pullup(unsigned char portname, unsigned char pinnumber, uint8_t enable);

/*
	Function Name        : write_low_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the low nibble of the port 
*/
void DIO_write_low_nibble(unsigned char portname,unsigned char value);

/*
	Function Name        : write_high_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the high nibble of the port 
*/
void DIO_write_high_nibble(unsigned char portname,unsigned char value);

#endif
