/*
 * LCD.h
 *
 * Created: 7/22/2025 7:56:09 PM
 *  Author: Mohamed-Galal
 */ 

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO.h"
#include "LCD_config.h"

// Main Commands
#define CLR_SCREEN           0x01
#define RETURN_HOME          0x02
#define FIRST_LINE           0x80
#define SECOND_LINE          0xC0

// Entry mode set
#define ENTRY_MODE           0x06 // Increment, no shift
#define ENTRY_MODE_RTL        0x04  // Decrement, no shift
#define ENTRY_MODE_INC_SHIFT  0x07
#define ENTRY_MODE_DEC_SHIFT  0x05

// Display Control Commands
#define DISPLAY_OFF               0x08  // display off, cursor off, blink off
#define DISPLAY_ON_CURSOR_OFF     0x0C  // display on, cursor off, blink off
#define CURSOR_OFF_BLINK_ON       0x0D  // display on, cursor off, blink on
#define CURSOR_ON_BLINK_OFF       0x0E  // display on, cursor on, blink off
#define CURSOR_ON_BLINK_ON        0x0F  // display on, cursor on, blink on

// Cursor or Display Shift
#define SHIFT_CURSOR_LEFT         0x10
#define SHIFT_CURSOR_RIGHT        0x14
#define SHIFT_DISPLAY_LEFT        0x18
#define SHIFT_DISPLAY_RIGHT       0x1C

// Function Set Variants
#define FUNCTION_SET_4BIT_1LINE   0x20
#define FUNCTION_SET_8BIT_1LINE   0x30

// Set DDRAM Address
#define SET_DDRAM_ADDR(x)         (0x80 | (x))  // use with custom positioning

// Set CGRAM Address
#define SET_CGRAM_ADDR(x)  (0x40 | ((x) << 3))  // each char takes 8 bytes

#if defined four_bits_mode || defined KIT_LCD
#define EN 0
#define RS 1
#define RW 2
#define FUNCTION_SET_4BIT_2LINE 0x28 // 4-bit, 2 lines, 5x8 font
 
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FUNCTION_SET_8BIT_2LINE   0x38 // 8-bit, 2 lines, 5x8 font
#endif // mode selection

void LCD_vInit(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);
#if defined KIT_LCD
void DIO_write_KIT_LCD_nibble(char portname, char start_bit, char end_bit, uint8_t value);
#endif
void LCD_create_custom_char(uint8_t location, uint8_t *pattern);

#endif // LCD_CONFIG_H_
