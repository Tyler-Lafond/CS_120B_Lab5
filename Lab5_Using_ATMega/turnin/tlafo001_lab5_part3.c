/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 5  Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char seq[7] = { 0x00, 0x01, 0x05, 0x15, 0x2A, 0x28, 0x20 };
unsigned char pos;

enum LED_States { LED_SMStart, LED_Unpress, LED_Press } LED_State;

void TickLED()
{
	switch(LED_State)
	{
		case LED_SMStart:
			pos = 0;
			PORTB = seq[pos];
			LED_State = LED_Unpress;
			break;
		case LED_Unpress:
			if ((PINA & 0x01) == 0x00)
			{
				if (pos < 0x06)
				{
					pos++;
				}
				else
				{
					pos = 0;
				}
				PORTB = seq[pos];
				LED_State = LED_Press;
			}
			else if ((PINA & 0x01) == 0x01)
			{
				LED_State = LED_Unpress;
			}
			break;
		case LED_Press:
			if ((PINA & 0x01) == 0x01)
			{
				LED_State = LED_Unpress;
			}
			else if ((PINA & 0x01) == 0x00)
			{
				LED_State = LED_Press;
			}
			break;
		default:
			LED_State = LED_SMStart;
			break;
	}

	switch(LED_State)
	{
		case LED_Unpress:
			break;
		case LED_Press:
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	PORTB = 0x00;
	LED_State = LED_SMStart;

    while (1) {
	TickLED();
    }
    return 1;
}
