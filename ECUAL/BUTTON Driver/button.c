/*
 * button.c
 *
 * Created: 8/16/2022 10:02:10 PM
 *  Author: Salem Elfaidy
 */ 


#include "button.h"


buttonErrors BUTTON_init(uint8_t buttonpin,uint8_t buttonport)
{
	
	buttonErrors returnedError;
	if (DIO_init( buttonpin , buttonport , IN) != DIO_OK)
	{
		returnedError = BUTTON_ERROR;
	}
	else
	{
		returnedError = BUTTON_OK;
	}
	
	return returnedError;

}



buttonErrors BUTTON_read(uint8_t buttonpin,uint8_t buttonport,uint8_t *value)
{
	
	buttonErrors returnedError;
	if (DIO_read( buttonpin , buttonport , value) != DIO_OK)
	{
		returnedError = BUTTON_ERROR;
	}
	else
	{
		returnedError = BUTTON_OK;
	}
	
	return returnedError;

}















/*test modules for the driver's APIs*/

/*
int main(void)
{
	
	  LED_init(0,PORT_A);
	  LED_init(1,PORT_A);
      BUTTON_init(2,PORT_D);	
	uint8_t value;
	while(1)
	{
		BUTTON_read(2,PORT_D,&value);
		if(value==HIGH)
		{
			LED_on(0,PORT_A);
		}
		else 
		{
			LED_off(0,PORT_A);
			LED_toggle(1,PORT_A);
		}
	}
}
*/