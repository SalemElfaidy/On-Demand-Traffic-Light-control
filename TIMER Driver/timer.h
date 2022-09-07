/*
 * timer.h
 *
 * Created: 8/20/2022 1:55:36 AM
 *  Author: Salem Elfaidy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "../STD_Types.h"

typedef enum timerMode_t
{
	
	Normal,PWM,CTC,FAST_PWM
	
}TimerMode_t;


typedef enum timerPrescaler_t
{
	
	TIMER_STOPED,NO_PRESCALER,PRESCALER_8,PRESCALER_64,PRESCALER_256,PRESCALER_1024
	
}TimerPrescaler_t;



void TIMER_mode(TimerMode_t mode);
void TIMER_init(uint8_t initialValue);
void TIMER_start(TimerPrescaler_t status,float32_t myDelay);


#endif 