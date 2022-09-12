/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Interface.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Andrew saied
 *
 * Version : V 1.0
 *******************************************************************************/







#ifndef _ADC_INTERFACE_H
#define _ADC_INTERFACE_H

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#include "std_types.h"


typedef enum{
	AREF,AVCC,RESERVED,internal_ref_volt
}ADC_ReferenceVolatge;


typedef enum{
pre2,pre4,pre8,pre16,pre32,pre64,pre128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;



void ADC_Init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_ReadValue(uint8 ch_num);

#endif
