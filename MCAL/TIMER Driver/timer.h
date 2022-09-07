/*
 * timer.h
 *
 * Created: 8/20/2022 1:55:36 AM
 *  Author: Salem Elfaidy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "../../Utilities/STD_Types.h"


typedef enum timerMode_t
{
	Normal,PWM,CTC,FAST_PWM
}TimerMode_t;


typedef enum timerPrescaler_t
{
	TIMER_STOPED,NO_PRESCALER,PRESCALER_8,PRESCALER_64,PRESCALER_256,PRESCALER_1024
}TimerPrescaler_t;


/*selecting timer mode*/
void TIMER_mode(TimerMode_t mode);

/*initializing timer take starting value*/
void TIMER_init(uint8_t initialValue);

/*this function take the prescaler value or timer stop and 
myDelay means time you want to delay in seconds*/
void TIMER_start(TimerPrescaler_t status,float32_t myDelay);

/*this function stop timer loop ,for example when you come back from 
ISR and wanna skip next instruction (while loop in timer implementation)*/
void stopTimerLoop(void);

#endif 