/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 3  Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tempA;
	unsigned char tempC;

    while (1) {
	tempA = PINA;
	tempC = 0x00;

	if ((tempA & 0x0F) > 12)
	{
		tempC = 0x3F;
	}
	else if ((tempA & 0x0F) > 9)
	{
		tempC = 0x3E;
	}
	else if ((tempA & 0x0F) > 6)
	{
		tempC = 0x3C;
	}
	else if ((tempA & 0x0F) > 4)
	{
		tempC = 0x38;
	}
	else if ((tempA & 0x0F) > 2)
	{
		tempC = 0x70;
	}
	else if ((tempA & 0x0F) > 0)
	{
		tempC = 0x60;
	}
	else
	{
		tempC = 0x40;
	}

	PORTC = tempC;
    }
    return 1;
}
