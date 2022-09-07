/*
 * application.c
 *
 * Created: 8/29/2022 5:49:10 PM
 *  Author: Salem Elfaidy
 */ 


#include "application.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/BUTTON Driver/button.h"
#include "../MCAL/TIMER Driver/timer.h"
#include "../MCAL/INTERRUPT Driver/interrupt.h"
#include "../Utilities/HELP_Function.h"

uint8_t going_to_nextStage,count1,error;



void APP_init(void)
{
	/*Leds initializing*/
	/*Cars traffic*/
	initCarsLeds(0,1,2);
	
	/*pedestrian traffic*/
	initPedestrianLeds(5,6,7);
	
	/*Timer initializing*/
	TIMER_mode(Normal);
	TIMER_init(0x00);
	
	/*Interrupt initializing*/
	error = BUTTON_init(2,PORT_D);
	if (error != BUTTON_OK)
	{
		return;
	}
	sei();
	EnalbleExternalInterrupt(THE_RISING_EDGE , INT_0);
	
}



void APP_start(void)
{
	
	while(1)
	{
		/*beginning from red led for cars*/
		going_to_nextStage = 0;	
		/*turn off four leds were turned on in the end of loop*/					   
		ledOffFunction(1,6,0,7);	
					    
		ledOnFunction(2,5);
		TIMER_start(NO_PRESCALER,5);				  /*start timer without prescaler for five sec*/
		
		
		count1=0;
		going_to_nextStage = 1;						  /*going to red led for cars*/
		while(count1 < 10)
		{
			ledToggleFunction(1,6);
			TIMER_start(PRESCALER_256,(0.5));	   	 /*blink every half second for 10 times*/
			count1++;
		}
		
		
		/*no (going_to_nextStage variable) needed cause in this stage no interrupt needed*/
		/*turn off four leds were turned on last two stages*/
		ledOffFunction(2,5,1,6);
		
		ledOnFunction(0,7);													 
	    TIMER_start(NO_PRESCALER,5);
		

		going_to_nextStage = 2;						  /*going to green led for cars*/
		while(count1 > 0)
		{
			ledToggleFunction(1,6);
			TIMER_start(PRESCALER_256,(0.5));
			count1--;
		}
	}
	
}



ISR(EXT_INT_0)
{
	interruputOperation();
}



void interruputOperation(void)							/* function do all interrupt operations */
{
	
	uint8_t cars_red_led , cars_green_led;
	error = LED_read(0,PORT_A,&cars_red_led);
		if (error != LED_OK)
		{
			return;
		}
	error = LED_read(2,PORT_A,&cars_green_led);
		if (error != LED_OK)
		{
			return;
		}
	
if ((cars_red_led == HIGH) && (going_to_nextStage == 1))
{
		TIMER_start(NO_PRESCALER,5);
		error = LED_off(0,PORT_A); 
		if (error != LED_OK)
		{
			return;
		}
		stopTimerLoop();						/* break timer coming from main loop to start from next stage when going back*/
} 
	
else if((cars_green_led == HIGH ) && (going_to_nextStage == 0))
{
		ledOnFunction(2,5);
		uint8_t count=0;
		while(count < 10)
		{
			ledToggleFunction(1,6);
			TIMER_start(PRESCALER_256,(0.5));
			count++;
		}
		
		ledOffFunction(2,5,1,6);
		ledOnFunction(0,7);
		TIMER_start(NO_PRESCALER,5);	
		

		while(count > 0)
		{
			error = LED_off(0,PORT_A);
			if (error != LED_OK)
			{
				return;
			}
			ledToggleFunction(1,6);
			TIMER_start(PRESCALER_256,(0.5));
			count--;
		}	
		

		ledOffFunction(0,7,1,6);
		ledOnFunction(2,5);
		TIMER_start(NO_PRESCALER,5);	
		stopTimerLoop();
		
}
	
else if ((cars_red_led == HIGH) && (going_to_nextStage == 2))         
{
	
		error = LED_off(0,PORT_A);
		if (error != LED_OK)
		{
			return;
		}
		error = LED_off(7,PORT_B);
		if (error != LED_OK)
		{
			return;
		}
		ledOnFunction(2,5);	                                                             
		uint8_t count=10;
		while(count > 0)			
		{
			ledToggleFunction(1,6);
			TIMER_start(PRESCALER_256,(0.5));
			count--;
		}
		
		ledOffFunction(2,5,1,6);
		ledOnFunction(0,7);
		TIMER_start(NO_PRESCALER,5);
		count1 = 10;								/*to start timer from beginning again*/
		error = LED_off(0,PORT_A);
		if (error != LED_OK)
		{
			return;
		}		
		
} 

else
{
			/*going to green led for pedestrians (no interrupt needed)*/
}
	
}




/*this function take pins of led you wanna turn off*/
void ledOffFunction(uint8_t led1,uint8_t led2,uint8_t led3,uint8_t led4)
{
	
		error = LED_off(led1,PORT_A);
		if (error != LED_OK)
		{
			return;
		}
		error = LED_off(led2,PORT_B);
		if (error != LED_OK)
		{
			return;
		}
		error = LED_off(led3,PORT_A);
		if (error != LED_OK)
		{
			return;
		}
		error = LED_off(led4,PORT_B);	
		if (error != LED_OK)
		{
			return;
		}		
	
}


/*this function take pins of led you wanna turn on*/
void ledOnFunction(uint8_t led1,uint8_t led2)
{
		error = LED_on(led1,PORT_A);
		if (error != LED_OK)
		{
			return;
		}
		error = LED_on(led2,PORT_B);
		if (error != LED_OK)
		{
			return;
		}
	
}


/*this function take pins of led you wanna toggle*/
void ledToggleFunction(uint8_t led1,uint8_t led2)
{
	
		error = LED_toggle(led1,PORT_A);
			if (error != LED_OK)
		{
			return;
		}
		error = LED_toggle(led2,PORT_B);
		if (error != LED_OK)
		{
			return;
		}
		
}

/*this function take pins of led you wanna initialize for cars*/
void initCarsLeds(uint8_t led1,uint8_t led2,uint8_t led3)
{
	error = LED_init(led1,PORT_A);
	if (error != LED_OK)
	{
		return;
	}
	error = LED_init(led2,PORT_A);
	if (error != LED_OK)
	{
		return;
	}
	error = LED_init(led3,PORT_A);
	if (error != LED_OK)
	{
		return;
	}	
}

/*this function take pins of led you wanna initialize for pedestrian*/
void initPedestrianLeds(uint8_t led1,uint8_t led2,uint8_t led3)
{
	error = LED_init(led1,PORT_B);
	if (error != LED_OK)
	{
		return;
	}
	error = LED_init(led2,PORT_B);
	if (error != LED_OK)
	{
		return;
	}
	error = LED_init(led3,PORT_B);
	if (error != LED_OK)
	{
		return;
	}
}