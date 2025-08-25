/*
 * LCD.c
 *
 * Created: 7/22/2025 7:55:56 PM
 *  Author: Mohamed-Galal
 */ 

#define  F_CPU 8000000UL
#include <avr/io.h>         
#include <util/delay.h>
#include <stdint.h>         
#include "LCD.h"

static void send_falling_edge(void)
{
	DIO_write(_LCD_EN_PORT, _LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_write(_LCD_EN_PORT, _LCD_EN_PIN, LOW);
	_delay_ms(2);
}

void LCD_vInit(void)
{
	_delay_ms(200);
	
	#if defined eight_bits_mode
	for (uint8_t pin = 0; pin <= 7; pin++) DIO_vsetPINDir(_LCD_PORT, pin, OUTPUT);
	
	#elif defined(four_bits_mode) || defined(KIT_LCD)
	DIO_vsetPINDir(_LCD_PORT, _LCD_D4, OUTPUT);
	DIO_vsetPINDir(_LCD_PORT, _LCD_D5, OUTPUT);
	DIO_vsetPINDir(_LCD_PORT, _LCD_D6, OUTPUT);
	DIO_vsetPINDir(_LCD_PORT, _LCD_D7, OUTPUT);
	#endif

	DIO_vsetPINDir(_LCD_EN_PORT, _LCD_EN_PIN, OUTPUT);
	DIO_vsetPINDir(_LCD_RS_PORT, _LCD_RS_PIN, OUTPUT);

	#if defined eight_bits_mode
	LCD_vSend_cmd(FUNCTION_SET_8BIT_2LINE);
	
	#elif defined(four_bits_mode) || defined(KIT_LCD)
	LCD_vSend_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vSend_cmd(FUNCTION_SET_4BIT_2LINE);
	#endif

	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_BLINK_OFF);
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
}

void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_write_port(_LCD_PORT, cmd);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, LOW);
	send_falling_edge();
	
	#elif defined four_bits_mode
	DIO_write_high_nibble(_LCD_PORT, cmd>>4);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, LOW);
	send_falling_edge();
	DIO_write_high_nibble(_LCD_PORT, cmd);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, LOW);
	send_falling_edge();
	
	#elif defined KIT_LCD
	DIO_write_KIT_LCD_nibble(_LCD_PORT, _LCD_D4, _LCD_D7, cmd>>4);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, LOW);
	send_falling_edge();
	
	DIO_write_KIT_LCD_nibble(_LCD_PORT, _LCD_D4, _LCD_D7, cmd & 0x0F);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, LOW);
	send_falling_edge();
	#endif
	
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port(_LCD_PORT, data);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, HIGH);
	send_falling_edge();
	
	#elif defined four_bits_mode
	DIO_write_high_nibble(_LCD_PORT, data>>4);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, HIGH);
	send_falling_edge();
	DIO_write_high_nibble(_LCD_PORT, data);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, HIGH);
	send_falling_edge();
	
	#elif defined KIT_LCD
	DIO_write_KIT_LCD_nibble(_LCD_PORT, _LCD_D4, _LCD_D7, data>>4);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, HIGH);
	send_falling_edge();
	DIO_write_KIT_LCD_nibble(_LCD_PORT, _LCD_D4, _LCD_D7, data & 0x0F);
	DIO_write(_LCD_RS_PORT, _LCD_RS_PIN, HIGH);
	send_falling_edge();
	#endif
	
	_delay_ms(1);
}

void LCD_vSend_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}

void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_movecursor(char row,char coloumn)
{
	char data = FIRST_LINE;
	if (row < 0 || row > 1 || coloumn < 0 || coloumn > 15)
	{
		data = FIRST_LINE;
	}
	else if (row == 0)
	{
		data = FIRST_LINE + coloumn;
	}
	else if (row == 1)
	{
		data = SECOND_LINE + coloumn;
	}
	
	LCD_vSend_cmd(data);
	_delay_ms(1);
}

#if defined KIT_LCD
void DIO_write_KIT_LCD_nibble(char portname, char start_bit, char end_bit, uint8_t value)
{
	value &= 0x0F;  // Keep only the lower 4 bits

	volatile uint8_t *port;

	// Get pointer to selected port
	switch (portname)
	{
		case 'A': case 'a': port = &PORTA; break;
		case 'B': case 'b': port = &PORTB; break;
		case 'C': case 'c': port = &PORTC; break;
		case 'D': case 'd': port = &PORTD; break;
		default: return;  // Invalid port
	}

	// Clear the target bits (start_bit to end_bit)
	for (char i = start_bit; i <= end_bit; i++)
	{
		*port &= ~(1 << i);
	}

	// Write each bit of value (0–3) to corresponding port bit
	for (char i = 0; i < 4; i++)
	{
		if (value & (1 << i)) {
			*port |= (1 << (start_bit + i));
		}
	}
}
#endif // KIT_LCD

void LCD_create_custom_char(uint8_t location, uint8_t *pattern)
{
	LCD_vSend_cmd(0x40 + (location * 8));  // Set CGRAM address
	for (uint8_t i = 0; i < 8; i++)
	{
		LCD_vSend_char(pattern[i]);
	}
}