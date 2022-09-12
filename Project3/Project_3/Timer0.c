/******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: Timer0.c
 *
 * Description: Source file for the Timer0 driver
 *
 * Author: Andrew saied
 *
 *******************************************************************************/
#include "Timer0.h"
#include "avr/io.h"
void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value
	OCR0  = ((PWM_TOP_VALUE*set_duty_cycle)/100); // Set Compare Value

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}
