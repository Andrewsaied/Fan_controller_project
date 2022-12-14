/******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: Timer0.h
 *
 * Description: Header file for the Timer0 driver
 *
 * Author: Andrew saied
 *
 *******************************************************************************/


#ifndef TIMER_0_H
#define TIMER_0_H

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_TOP_VALUE		255


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Timer0_PWM_Init(unsigned char set_duty_cycle);


#endif /* TIMER_0_H */
