/*
 * timer.c
 *
 * Created: 8/20/2022 1:55:16 AM
 *  Author: Salem Elfaidy
 */ 


#include "timer.h"




void TIMER_mode(TimerMode_t mode)
{
	
	TCCR0 = 0X00;
	if (mode == Normal)
	{
		
	}
	else if (mode == PWM)
	{
		TCCR0 |= (1<<6);
	}
	else if (mode == CTC)
	{
		TCCR0 |= (1<<3);
	}	
	else 
	{
		TCCR0 |= (1<<3);
		TCCR0 |= (1<<6);
	}
	
	
}



void TIMER_init(uint8_t initialValue)
{
	
	TCNT0 = initialValue;
	
}




void TIMER_start(TimerPrescaler_t status,float32_t myDelay)
{
	uint32_t overflowCounter = 0 , numperOfOverflows;
	
	TCCR0 = 0X00;
	if(status==TIMER_STOPED)
	{
		numperOfOverflows = 0 ;
	}
	else if(status==NO_PRESCALER)
	{
		TCCR0 |= (1<<0);
		numperOfOverflows = (myDelay/(256*(0.000001)))+1;  //adding one causing int near the number like 0.1 -> 0.0
	}
	else if(status==PRESCALER_8)
	{		
			TCCR0 |= (1<<1);
		numperOfOverflows = (myDelay/(0.002048))+1;  
	}
	else if(status==PRESCALER_64)
	{		
			TCCR0 |= (1<<1);
			TCCR0 |= (1<<0);
		numperOfOverflows = (myDelay/(0.016384))+1;
	}
	else if(status==PRESCALER_256)
	{
		TCCR0 |= (1<<2);
		numperOfOverflows = (myDelay/(0.065536))+1;
	}	
	else
	{
		TCCR0 |= (1<<2);
		TCCR0 |= (1<<0);
		numperOfOverflows = (myDelay/(0.262144))+1;
	}
	
	while(overflowCounter<numperOfOverflows)
	{
		
		while((TIFR&(1<<0))== 0);         //wait till overflow flag set..
		
	 TIFR |= (1<<0);                 //clear the overflow flag (avoid interrupt)
	 overflowCounter++;                    
		
	}
	

	//timer stop..
	TCCR0 = 0X00;
	
	
}

