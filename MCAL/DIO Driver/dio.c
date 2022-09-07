/*
 * dio.c
 *
 * Created: 8/15/2022 5:31:02 PM
 *  Author: Salem Elfaidy
 */ 



#include "dio.h"

dioErrors DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction)
{
	
dioErrors returnedError	;
if((pinNumber > 7) || (pinNumber<0))
{
	returnedError = WRONG_PINNUMBER;
}

	switch(portNumber)
	{
				case PORT_A:
			if (direction == IN)
			{
				DDRA &=~(1<<pinNumber); //Direction is input..
				returnedError = DIO_OK;
			} 
			else if(direction == OUT)
			{
				DDRA |=(1<<pinNumber); //Direction is output..
				return DIO_OK;
			}
			else
			{
				returnedError = WRONG_DIRECTION;
			}
			break;
	
			case PORT_B:
			if (direction == IN)
			{
				DDRB &=~(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else if(direction == OUT)
			{
				DDRB |=(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else
			{
				returnedError = WRONG_DIRECTION;
			}
			break;
			
			case PORT_C:
			if (direction == IN)
			{
				DDRC &=~(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else if	(direction == OUT)				{
				DDRC |=(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else
			{
				returnedError = WRONG_DIRECTION;
			}
			break;	
	
			case PORT_D:
			if (direction == IN)
			{
				DDRD &=~(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else if(direction == OUT)
			{
				DDRD |=(1<<pinNumber);
				returnedError = DIO_OK;
			}
			else
			{
				returnedError = WRONG_DIRECTION;
			}
			break;
			
			default:
			returnedError = WRONG_PORTNUMBER;
			break;
			
	}		
	
	
	return returnedError;
		
}

dioErrors DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value)
{

dioErrors returnedError	;
if((pinNumber > 7) || (pinNumber<0))
{
	returnedError = WRONG_PINNUMBER;
}
	
	switch(portNumber)
	{
		case PORT_A:
		if (value == LOW)
		{
			PORTA &=~(1<<pinNumber); //output is zero volt..
			returnedError = DIO_OK;
		}
		else if(value == HIGH)
		{
			PORTA |=(1<<pinNumber); //output is 5 volt..
			returnedError = DIO_OK;
		}
		else
		{
			returnedError = WRONG_VOLTAVE_VALUE;
		}
		break;
		
		case PORT_B:
		if (value == LOW)
		{
			PORTB &=~(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else if(value == HIGH)
		{
			PORTB |=(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else
		{
			returnedError = WRONG_VOLTAVE_VALUE;
		}
		break;
		
		case PORT_C:
		if (value == LOW)
		{
			PORTC &=~(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else if(value == HIGH)
		{
			PORTC |=(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else
		{
			returnedError = WRONG_VOLTAVE_VALUE;
		}
		break;
		
		case PORT_D:
		if (value == LOW)
		{
			PORTD &=~(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else if(value == HIGH)
		{
			PORTD |=(1<<pinNumber);
			returnedError = DIO_OK;
		}
		else
		{
			returnedError = WRONG_VOLTAVE_VALUE;
		}
		break;
		
		default:
		returnedError = WRONG_PORTNUMBER;
		break;
					
	}	
	
	return returnedError;
	
}

dioErrors DIO_toggle(uint8_t pinNumber,uint8_t portNumber)
{

dioErrors returnedError	;
if((pinNumber > 7) || (pinNumber<0))
{
	returnedError = WRONG_PINNUMBER;
}
		
		switch(portNumber)
		{
			case PORT_A:
				PORTA ^=(1<<pinNumber); //toggle pinNumber..
			    returnedError = DIO_OK;
				break;
				
			case PORT_B:
				PORTB ^=(1<<pinNumber); //toggle pinNumber..
				returnedError = DIO_OK;
				break;
				
			case PORT_C:
				PORTC ^=(1<<pinNumber); //toggle pinNumber..
				returnedError = DIO_OK;
				break;
				
			case PORT_D:
				PORTD ^=(1<<pinNumber); //toggle pinNumber..
				returnedError = DIO_OK;
				break;
				
			default:
			returnedError = WRONG_PORTNUMBER;
			break;
				
		}
		
	return returnedError;	
}

dioErrors DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value)
{

dioErrors returnedError	;
if((pinNumber > 7) || (pinNumber<0))
{
	returnedError = WRONG_PINNUMBER;
}
	
		switch(portNumber)
		{
			case PORT_A:
			*value = ((PINA>>pinNumber)&1); //read pin..
			returnedError = DIO_OK;
			break;
			
			case PORT_B:
			*value = ((PINB>>pinNumber)&1); //read pin..
			returnedError = DIO_OK;
			break;
				
			case PORT_C:
			*value = ((PINC>>pinNumber)&1); //read pin..
			returnedError = DIO_OK;
			break;
							
			case PORT_D:
			*value = ((PIND>>pinNumber)&1); //read pin..
			returnedError = DIO_OK;
			break;

			default:
			returnedError = WRONG_PORTNUMBER;	
			break;			
		}
	
	return returnedError;
	
}











/*test modules for the driver's APIs*/

/*
int main (void)
{
	DIO_init(2,PORT_A,OUT);
	DIO_init(1,PORT_A,OUT);
	DIO_init(0,PORT_A,OUT);	
	uint8_t pin=0;
	while(1)
	{
		
		DIO_toggle(2,PORT_A);
		DIO_read(2,PORT_A,&pin);
		DIO_write(pin,PORT_A,HIGH);
		
	}
}

*/