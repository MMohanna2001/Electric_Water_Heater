
/* UTILIES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL */
#include "DIO_interface.h"
#include "TMR1_interface.h"
/* HAL */
#include "DCM_interface.h"

//Function to initialize DC motor pins
void DCM_init(void)
{
	//Set the direction of the motor pins as output
	DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);


}

//Function to turn on the DC motor in the specified direction
void DCM_on(u8 motorDirection)
{
	if(CW == motorDirection) // Direction is clockwise
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	}
	else // Direction is counter clockwise
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
	}
}

//Function to control the speed of the DC motor
void DCM_ctrlSpeed(u8 motorSpeed)
{
	// Calculate the compare match value for Timer1 using the input Duty Cycle
	TMR1_setCompareMatchValueA((motorSpeed * (4999 + 1))/100);
	TMR1_start();
}

//Function to turn off the DC motor
void DCM_off(void)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
}

