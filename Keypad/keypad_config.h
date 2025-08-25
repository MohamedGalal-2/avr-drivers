/*
 * keypad_config.h
 *
 * Created: 2/28/2025 7:55:06 PM
 *  Author: Mohamed-Galal
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

// Define the arrays as const to store them in flash (ROM)
static const char row_Ports[KEYPAD_ROWS]     = {'B', 'B', 'B', 'B'};
static const char row_Pins[KEYPAD_ROWS]      = {4, 5, 6, 7};
static const char coloumn_Ports[KEYPAD_COLS] = {'D', 'D', 'D', 'D'};
static const char coloumn_Pins[KEYPAD_COLS]  = {2, 3, 4, 5};

static const char keypad_matrix[KEYPAD_ROWS][KEYPAD_COLS] = {
	{'1', '2', '3', '+'},
	{'4', '5', '6', '-'},
	{'7', '8', '9', '*'},
	{'A', '0', '=', '/'}
};

#define NOTPRESSED 0xFF

#endif /* KEYPAD_CONFIG_H_ */