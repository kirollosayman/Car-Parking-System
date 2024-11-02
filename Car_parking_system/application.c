/*Include ECAL drivers*/
#include "leds.h"
#include "ultrasonic.h"
#include "lcd.h"
#include "buzzer.h"
#include <avr/interrupt.h>
#include <util/delay.h>

//Create flags by using bitfield
struct my_bitfield
{
	uint8 stop :1; //used to print stop massage one time instead of clear and print
	uint8 :7;
}flags;

//Needed variable
uint16 distance=0;

//main Function
int main (void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	//initial values
	flags.stop=0;

	/*call init functions*/
	LEDS_init();
	Ultrasonic_init();
	LCD_init();
	Buzzer_init();

	//LCD Start up
	//LCD clear screen
	LCD_clearScreen();
	//LCD write text massage
	LCD_displayStringRowColumn(0,0,"Distance = XXXcm");
	while(1)
	{
		//Measure the distance
		distance= Ultrasonic_readDistance();
		//LCD show distance
		LCD_moveCursor(0,11);
		LCD_intgerToString(distance);
		if(distance<10)
		{
			LCD_displayString("  ");
		}
		else if(distance<100)
		{
			LCD_displayCharacter(' ');
		}

		//Leds & buzzer condition

		if(distance > 20)
		{
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
		}
		else if(distance >= 16)
		{
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
		}
		else if(distance >= 11)
		{
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
			Buzzer_off();
		}
		else if(distance >= 6)
		{
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			Buzzer_off();
			if(!flags.stop)
			{
				//LCD delete stop
				LCD_displayStringRowColumn(1,6,"     ");
				flags.stop=1;
			}
		}
		else if(distance >= 0)
		{
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();

			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			Buzzer_on();

			if(flags.stop)
			{
				//LCD write stop
				LCD_displayStringRowColumn(1,6,"Stop!");
				flags.stop=0;
			}
		}
		else if(distance >= 0)
		{
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			Buzzer_on();
			_delay_ms(500);
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			_delay_ms(500);

			if(flags.stop)
			{
				//LCD write stop
				LCD_displayStringRowColumn(1,6,"Stop!");
				flags.stop=0;
			}
		}
	}
}
