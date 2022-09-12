 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_Program.c
 *
 * Description: Source file for the AVR GPIO driver
 *
* Author: Andrew saied
 *
 * Version : V 1.0
 *******************************************************************************/

#include "GPIO_Interface.h"
#include "avr/io.h"
#include "common_macros.h" /* To use the macros like SET_BIT */


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
error_state GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	error_state state=NOT_OK;
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if(1==direction)
	{state=OK;
		switch(port_num)
		{

			case 0: SET_BIT(DDRA,pin_num); break;
			case 1: SET_BIT(DDRB,pin_num); break;
			case 2: SET_BIT(DDRC,pin_num); break;
			case 3: SET_BIT(DDRD,pin_num); break;
			default:state=NOT_OK;break;
			
		}
	}
	else if(0==direction)
	{state=OK;
				switch(port_num)
		{
			case 0:CLEAR_BIT(DDRA,pin_num); break;
			case 1:CLEAR_BIT(DDRB,pin_num); break;
			case 2:CLEAR_BIT(DDRC,pin_num); break;
			case 3:CLEAR_BIT(DDRD,pin_num); break;
			default:state=NOT_OK;break;
	   }
	}

	return state;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
error_state GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	error_state state=NOT_OK;
	if(1==value)
	{state=OK;
		switch(port_num)
		{
			case 0: SET_BIT(PORTA,pin_num); break;
			case 1: SET_BIT(PORTB,pin_num); break;
			case 2: SET_BIT(PORTC,pin_num); break;
			case 3: SET_BIT(PORTD,pin_num); break;
			default:state=NOT_OK;break;
			
		}
	}
	else if(0==value)
	{
		state=OK;
				switch(port_num)
		{
			case 0:CLEAR_BIT(PORTA,pin_num); break;
			case 1:CLEAR_BIT(PORTB,pin_num); break;
			case 2:CLEAR_BIT(PORTC,pin_num); break;
			case 3:CLEAR_BIT(PORTD,pin_num); break;
			default:state=NOT_OK;break;
	}
	}
	return state;

}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 Value;
	if (pin_num<0 || pin_num>7)
	{
		
		return -1;
	}
	switch(port_num)
	{
		case 0: Value=GET_BIT(PINA,pin_num); break;
		case 1: Value=GET_BIT(PINB,pin_num); break;
		case 2: Value=GET_BIT(PINC,pin_num); break;
		case 3: Value=GET_BIT(PIND,pin_num); break;
		
	}
	return Value;

}

/*
 * Description :
 * Toggel and  the required pin,
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
error_state GPIO_ToggelPin(uint8 port_num,uint8 pin_num)
{
	error_state state=NOT_OK;
	switch(port_num)
	{
		case 0: TOGGLE_BIT(PORTA,pin_num);state=OK; break;
		case 1: TOGGLE_BIT(PORTB,pin_num);state=OK; break;
		case 2: TOGGLE_BIT(PORTC,pin_num);state=OK; break;
		case 3: TOGGLE_BIT(PORTD,pin_num);state=OK; break;
		default:state=NOT_OK;break;
	}
	return state;
}



/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
error_state GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	error_state state=NOT_OK;
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			state=OK;
			break;
		case PORTB_ID:
			DDRB = direction;
			state=OK;
			break;
		case PORTC_ID:
			DDRC = direction;
			state=OK;
			break;
		case PORTD_ID:
			DDRD = direction;
			state=OK;
			break;
		}
	}
	return state;
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
error_state GPIO_writePort(uint8 port_num, uint8 value)
{
	error_state state=NOT_OK;
	switch(port_num)
	{
		case 0: PORTA=value;state=OK; break;
		case 1: PORTB=value;state=OK; break;
		case 2: PORTC=value;state=OK; break;
		case 3: PORTD=value;state=OK; break;
		default:state=NOT_OK;break;
	}
	return state;
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{	
uint8 Value;
	
	if (port_num<0|| port_num>NUM_OF_PORTS)
	{
		
		return -1;
	}
	switch(port_num)
	{
		case 0: Value=PINA; break;
		case 1: Value=PINB; break;
		case 2: Value=PINC; break;
		case 3: Value=PIND; break;
		
	}
	return Value;
	
}
