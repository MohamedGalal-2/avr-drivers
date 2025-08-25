/*
 * delay.c
 *
 * Created: 4/29/2025 7:55:56 PM
 *  Author: Mohamed-Galal
 */ 

#include <avr/io.h>
#include "std_macros.h"
#include "keypad.h"

void keypad_vInit(void)
{
	DIO_vsetPINDir(row_Ports[0], row_Pins[0], OUTPUT);
	DIO_vsetPINDir(row_Ports[1], row_Pins[1], OUTPUT);
	DIO_vsetPINDir(row_Ports[2], row_Pins[2], OUTPUT);
	DIO_vsetPINDir(row_Ports[3], row_Pins[3], OUTPUT);
	DIO_vsetPINDir(coloumn_Ports[0], coloumn_Pins[0], INPUT);
	DIO_vsetPINDir(coloumn_Ports[1], coloumn_Pins[1], INPUT);
	DIO_vsetPINDir(coloumn_Ports[2], coloumn_Pins[2], INPUT);
	DIO_vsetPINDir(coloumn_Ports[3], coloumn_Pins[3], INPUT);
	DIO_enable_pullup(coloumn_Ports[0], coloumn_Pins[0], ENABLE);
	DIO_enable_pullup(coloumn_Ports[1], coloumn_Pins[1], ENABLE);
	DIO_enable_pullup(coloumn_Ports[2], coloumn_Pins[2], ENABLE);
	DIO_enable_pullup(coloumn_Ports[3], coloumn_Pins[3], ENABLE);
}

char keypad_u8check_press(void)
{
	uint8_t row, coloumn;
	unsigned char x = NOTPRESSED;
	char return_val = NOTPRESSED;
	
	for (row = 0; row < 4; row++)
	{
		DIO_write(row_Ports[0], row_Pins[0], HIGH);
		DIO_write(row_Ports[1], row_Pins[1], HIGH);
		DIO_write(row_Ports[2], row_Pins[2], HIGH);
		DIO_write(row_Ports[3], row_Pins[3], HIGH);
		
		DIO_write(row_Ports[row], row_Pins[row], LOW);
		for(coloumn = 0; coloumn < 4; coloumn++)
		{
			x = DIO_u8read(coloumn_Ports[coloumn], coloumn_Pins[coloumn]);
			
			if (x == 0)
			{
				return_val = keypad_matrix[row][coloumn];
				break;
			}
		}
		if (x == 0)
		{
			break;
		}
	}
	
	return return_val;
}