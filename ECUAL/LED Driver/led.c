/*
 * led.c
 *
 * Created: 8/16/2022 1:55:57 AM
 *  Author: Salem Elfaidy
 */ 



#include "led.h"

ledErrors LED_init(uint8_t ledpin,uint8_t ledport)
{
	
	ledErrors returnedError;
	 if (DIO_init(ledpin,ledport,OUT) != DIO_OK)
	 {
		 returnedError = LED_ERROR;
	 } 
	 else
	 {
		 returnedError = LED_OK;
	 }
	 
	 return returnedError;
	 
}



ledErrors LED_on(uint8_t ledpin,uint8_t ledport)
{

	ledErrors returnedError;
	if (DIO_write(ledpin,ledport,HIGH) != DIO_OK)
	{
		returnedError = LED_ERROR;
	}
	else
	{
		returnedError = LED_OK;
	}
	
	return returnedError;

}



ledErrors LED_off(uint8_t ledpin,uint8_t ledport)
{
	
	ledErrors returnedError;
	if (DIO_write(ledpin,ledport,LOW) != DIO_OK)
	{
		returnedError = LED_ERROR;
	}
	else
	{
		returnedError = LED_OK;
	}
	
	return returnedError;

}



ledErrors LED_toggle(uint8_t ledpin,uint8_t ledport)
{
	
	ledErrors returnedError;
	if (DIO_toggle(ledpin,ledport) != DIO_OK)
	{
		returnedError = LED_ERROR;
	}
	else
	{
		returnedError = LED_OK;
	}
	
	return returnedError;

}


ledErrors LED_read(uint8_t ledpin,uint8_t ledport,uint8_t *value)
{
	
	ledErrors returnedError;
	if (DIO_read(ledpin,ledport,value) != DIO_OK)
	{
		returnedError = LED_ERROR;
	}
	else
	{
		returnedError = LED_OK;
	}
	
	return returnedError;

}











/*test modules for the driver's APIs*/

/*
int main(void)
{
	
	  LED_init(0,PORT_A);
	  LED_init(1,PORT_A);
	  LED_init(2,PORT_A);	
	  uint8_t pin=0;
	
	while(1)
	{
		LED_toggle(2,PORT_A);
		LED_read(2,PORT_A,&pin);
		LED_on(pin,PORT_A);		
		
	}
}
*/