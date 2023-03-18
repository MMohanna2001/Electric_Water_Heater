
/* UTILIES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "LED_interface.h"

//Function to initialize the LED by setting its pin as Output
void LED_init(void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
}

//Function to Turn ON the LED
void LED_on(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
}

//Function to Turn OFF the LED
void LED_off(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
}

//Function to Toggle the LED
void LED_toggle(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN5);
}

