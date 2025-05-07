/*
 * DIO.c
 *
 * Created: 4/26/2025 7:55:56 PM
 *  Author: Mohamed-Galal
 */ 

#include <avr/io.h>
#include "std_macros.h"

#define NUM_PORTS 4

volatile uint8_t* DDR[NUM_PORTS]  = { &DDRA, &DDRB, &DDRC, &DDRD };
volatile uint8_t* PORT[NUM_PORTS] = { &PORTA, &PORTB, &PORTC, &PORTD };
volatile uint8_t* PIN[NUM_PORTS]  = { &PINA, &PINB, &PINC, &PIND };

static int get_port_index(char portname) {
	switch (portname) {
		case 'A': case 'a': return 0;
		case 'B': case 'b': return 1;
		case 'C': case 'c': return 2;
		case 'D': case 'd': return 3;
		default: return -1;
	}
}

void DIO_vsetPINDir(char portname, uint8_t pinnumber, uint8_t direction) {
	int idx = get_port_index(portname);
	if (idx >= 0) {
		if (direction) SET_BIT(*DDR[idx], pinnumber);
		else CLR_BIT(*DDR[idx], pinnumber);
	}
}

void DIO_write(char portname, uint8_t pinnumber, uint8_t value) {
	int idx = get_port_index(portname);
	if (idx >= 0) {
		if (value) SET_BIT(*PORT[idx], pinnumber);
		else CLR_BIT(*PORT[idx], pinnumber);
	}
}

uint8_t DIO_u8read(char portname, uint8_t pinnumber) {
	int idx = get_port_index(portname);
	return (idx >= 0) ? READ_BIT(*PIN[idx], pinnumber) : 0;
}

void DIO_toggle(char portname, uint8_t pinnumber) {
	int idx = get_port_index(portname);
	if (idx >= 0) TOG_BIT(*PORT[idx], pinnumber);
}

void DIO_set_port_direction(char portname, uint8_t direction) {
	int idx = get_port_index(portname);
	if (idx >= 0) *DDR[idx] = direction;
}

void DIO_write_port(char portname, uint8_t value) {
	int idx = get_port_index(portname);
	if (idx >= 0) *PORT[idx] = value;
}

uint8_t DIO_read_port(char portname) {
	int idx = get_port_index(portname);
	return (idx >= 0) ? *PIN[idx] : 0;
}

void DIO_toggle_port(char portname) {
	int idx = get_port_index(portname);
	if (idx >= 0) *PORT[idx] ^= 0xFF;
}

void DIO_enable_pullup(char portname, uint8_t pinnumber, uint8_t enable) {
	int idx = get_port_index(portname);
	if (idx >= 0) {
		CLR_BIT(*DDR[idx], pinnumber); // ensure input
		if (enable) SET_BIT(*PORT[idx], pinnumber);
		else CLR_BIT(*PORT[idx], pinnumber);
	}
}