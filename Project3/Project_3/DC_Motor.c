/******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Andrew saied
 *
 *******************************************************************************/

#include "DC_Motor.h"
#include "GPIO_Interface.h"
#include "Timer0.h"

/*
	The Function responsible for setup the direction for the two
	motor pins through the GPIO driver.
	Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_Init(void)
{
	/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	GPIO_setupPinDirection(DC_PORT,DC_PIN_4 , OUTPUT_PIN);

	/* Set the direction for the motor */
	GPIO_setupPinDirection(DC_PORT,DC_PIN_1,OUTPUT_PIN);
	GPIO_setupPinDirection(DC_PORT,DC_PIN_2,OUTPUT_PIN);

	/* Make the motor initally stopped */
	GPIO_writePin(DC_PORT,DC_PIN_1,LOGIC_LOW);
	GPIO_writePin(DC_PORT,DC_PIN_2,LOGIC_LOW);
}


/*
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 *	stop the motor based on the state input state value.
 *
 *	Send the required duty cycle to the PWM driver based on the
 *	required speed value.
 *
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

		switch(state)
		{
		case CW: 
			/* Motor works in clockwise rotation */
			GPIO_writePin(DC_PORT,DC_PIN_1,LOGIC_HIGH);
			GPIO_writePin(DC_PORT,DC_PIN_2,LOGIC_LOW);

			break;
		case ACW: 	
			/* Motor works in anti-clockwise rotation */
			GPIO_writePin(DC_PORT,DC_PIN_1,LOGIC_LOW);
			GPIO_writePin(DC_PORT,DC_PIN_2,LOGIC_HIGH);

			break;
		case STOP:
			/* Motor stops from working */
			GPIO_writePin(DC_PORT,DC_PIN_1,LOGIC_LOW);
			GPIO_writePin(DC_PORT,DC_PIN_2,LOGIC_LOW);
			break;
			deafult:
			/* Motor stops from working */
			GPIO_writePin(DC_PORT,DC_PIN_1,LOGIC_LOW);
			GPIO_writePin(DC_PORT,DC_PIN_2,LOGIC_LOW);
			break;
		}
		Timer0_PWM_Init(speed);
}
