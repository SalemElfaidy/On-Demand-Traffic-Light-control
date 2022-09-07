/*
 * dio.h
 *
 * Created: 8/15/2022 5:31:22 PM
 *  Author: Salem Elfaidy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/STD_Types.h"
#include <avr/io.h>

/*Port number sent*/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

/*Direction sent*/
#define IN 0         
#define OUT 1       

/*Voltage value sent*/
#define LOW 0         
#define HIGH 1     

/*user expected errors*/
 typedef enum DioErrors
 {
	 WRONG_PINNUMBER,WRONG_PORTNUMBER,WRONG_DIRECTION,WRONG_VOLTAVE_VALUE,DIO_OK
 }dioErrors;
  

dioErrors DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction);				     /*initialize dio direction */
dioErrors DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value);			        /*writing high or zero voltage on pin*/
dioErrors DIO_toggle(uint8_t pinNumber,uint8_t portNumber);
dioErrors DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value);			       /*reading pin states high or low*/



#endif 