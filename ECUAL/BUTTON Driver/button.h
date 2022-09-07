/*
 * button.h
 *
 * Created: 8/16/2022 10:02:29 PM
 *  Author: Salem Elfaidy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

/*Button state..*/
#define LOW 0
#define HIGH 1


/*user expected errors*/
typedef enum ButtonErrors
{
	BUTTON_ERROR,BUTTON_OK
}buttonErrors;



buttonErrors BUTTON_init(uint8_t buttonpin,uint8_t buttonport);
/*reading button state*/
buttonErrors BUTTON_read(uint8_t buttonpin,uint8_t buttonport,uint8_t *value);


#endif 