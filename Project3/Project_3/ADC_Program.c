/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Program.c
 *
 * Description: Source file for the AVR ADC driver
 *
* Author: Andrew saied
 *
 * Version : V 1.0
 *******************************************************************************/
 #include "ADC_Interface.h"
 #include <avr/io.h>
 #include "common_macros.h" /* To use the macros like SET_BIT */
void ADC_Init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose to connect internal reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;
	ADMUX|=((Config_Ptr->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = configured by Config_ptr dynamically --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (Config_Ptr->prescaler);
}

 
 
uint16 ADC_ReadValue(uint8 ch_num)
{
		ADMUX = ADMUX & 0b11100000;

		ADMUX |= ch_num;
		SET_BIT(ADCSRA,6);

		while(GET_BIT(ADCSRA,4)==0)
		{}
		SET_BIT(ADCSRA,4);
		return ADC;
		
}
