#include "leds.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initializes all Leds (red, green, blue) pins direction.
   Turn off all the Leds
*/
void LEDS_init(void)
{
	//Initializes all Leds (red, green, blue) pins direction
	GPIO_setupPinDirection(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,PIN_OUTPUT);
	// Turn off all the Leds
#ifdef Positive_logic
	GPIO_writePin(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_LOW);
#else
	GPIO_writePin(LEDS_PORT_ID,LEDS_RED_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(LEDS_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(LEDS_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_HIGH);
#endif
}

/*
 * Description :
 Turns on the specified LED.
*/
void LED_on(LED_ID id)
{
#ifdef Positive_logic
	switch(id)
	{
		case RED:
			GPIO_writePin(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,LOGIC_HIGH);
			break;
		case GREEN:
			GPIO_writePin(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_HIGH);
			break;
		case BLUE:
			GPIO_writePin(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_HIGH);
			break;
	}
#else
	switch(id)
	{
		case RED:
			GPIO_writePin(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,LOGIC_LOW);
			break;
		case GREEN:
			GPIO_writePin(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_LOW);
			break;
		case BLUE:
			GPIO_writePin(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_LOW);
			break;
	}
#endif
}

/*
 * Description :
 Turns off the specified LED.
*/
void LED_off(LED_ID id)
{
#ifdef Positive_logic
	switch(id)
	{
		case RED:
			GPIO_writePin(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,LOGIC_LOW);
			break;
		case GREEN:
			GPIO_writePin(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_LOW);
			break;
		case BLUE:
			GPIO_writePin(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_LOW);
			break;
	}
#else
	switch(id)
	{
		case RED:
			GPIO_writePin(LEDS_RED_PORT_ID,LEDS_RED_PIN_ID,LOGIC_HIGH);
			break;
		case GREEN:
			GPIO_writePin(LEDS_GREEN_PORT_ID,LEDS_GREEN_PIN_ID,LOGIC_HIGH);
			break;
		case BLUE:
			GPIO_writePin(LEDS_BLUE_PORT_ID,LEDS_BLUE_PIN_ID,LOGIC_HIGH);
			break;
	}
#endif
}
