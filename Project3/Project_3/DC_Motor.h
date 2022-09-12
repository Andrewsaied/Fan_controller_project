/******************************************************************************
 *
 * Module:DC_MOTOR
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Andrew saied
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define DC_PORT                  PORTB_ID


/* Keypad Port Configurations */


#define DC_PIN_1           PIN0_ID
#define DC_PIN_2       	   PIN1_ID
#define DC_PIN_4       	   PIN3_ID

/* Keypad button logic configurations */

#define OUTPUT_PIN	1
#define INPUT_PIN	0


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	CW,ACW,STOP
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* KEYPAD_H_ */
