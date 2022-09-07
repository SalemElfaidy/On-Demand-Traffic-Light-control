/*
 * led.h
 *
 * Created: 8/16/2022 1:56:18 AM
 *  Author: Salem Elfaidy
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"


/*user expected errors*/
typedef enum LedErrors
{
	LED_ERROR,LED_OK
}ledErrors;


/*initialize LED */
ledErrors LED_init(uint8_t ledpin,uint8_t ledport);	
/*turn on led*/			
ledErrors LED_on(uint8_t ledpin,uint8_t ledport);
/*turn off led*/
ledErrors LED_off(uint8_t ledpin,uint8_t ledport);
/*make led blinking*/
ledErrors LED_toggle(uint8_t ledpin,uint8_t ledport);
/*read led state*/
ledErrors LED_read(uint8_t ledpin,uint8_t ledport,uint8_t *value);

#endif 