/*
 ================================================================================================
 Name        : miniproject4.c
 Author      : Toka Mohamed
 Description : measure the distance using ultrasonic sensor
 Date        : 25/10/2021
 ================================================================================================
 */
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */

extern uint8 g_edgeCount;

int main()
{
	uint16 Distance=0;
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	LCD_init(); /*initialize the LCD*/
	Ultrasonic_init(); /*initialize the ultrasonic*/
	LCD_displayString("Distance=     cm"); /*display only once*/
	while(1)
	{
		if(g_edgeCount == 2)
		{
			g_edgeCount = 0;
			Distance = Ultrasonic_readDistance();
			LCD_moveCursor(0,10);
			LCD_intgerToString(Distance);
		}
	}
}

