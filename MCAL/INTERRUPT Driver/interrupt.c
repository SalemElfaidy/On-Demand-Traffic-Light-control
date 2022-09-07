/*
 * CFile1.c
 *
 * Created: 8/28/2022 10:30:36 PM
 *  Author: Salem Elfaidy
 */ 



#include "interrupt.h"


void EnalbleExternalInterrupt(interruptSense sense,InterruptEnable enable)
{
	
if ((sense == THE_LOW_LEVEL) && (enable == INT_0))
{
	MCUCR &=~(1<<0);
	MCUCR &=~(1<<1);
	GICR |=(1<<6);
} 

else if ((sense == ANY_LOGICAL_CHANGE) && (enable == INT_0))
{
		MCUCR |=(1<<0);
		MCUCR &=~(1<<1);
		GICR |=(1<<6);
}

else if ((sense == THE_FALLING_EDGE) && (enable == INT_0))
{
	MCUCR &=~(1<<0);
	MCUCR |=(1<<1);
	GICR |=(1<<6);
}	

else if ((sense == THE_RISING_EDGE) && (enable == INT_0))
{
	MCUCR |=(1<<0);
	MCUCR |=(1<<1);
	GICR |=(1<<6);
}	
	
else if ((sense == THE_LOW_LEVEL) && (enable == INT_1))
{
	MCUCR &=~(1<<2);
	MCUCR &=~(1<<3);
	GICR |=(1<<7);
}

else if ((sense == ANY_LOGICAL_CHANGE) && (enable == INT_1))
{
	MCUCR |=(1<<2);
	MCUCR &=~(1<<3);
	GICR |=(1<<7);
}

else if ((sense == THE_FALLING_EDGE) && (enable == INT_1))
{
	MCUCR &=~(1<<2);
	MCUCR |=(1<<3);
	GICR |=(1<<7);
}

else if ((sense == THE_RISING_EDGE) && (enable == INT_1))
{
	MCUCR |=(1<<2);
	MCUCR |=(1<<3);
	GICR |=(1<<7);
}	

else if ((sense == THE_FALLING_EDGE) && (enable == INT_2))
{
	MCUCSR &=~(1<<6);
	GICR |=(1<<5);
}

else if ((sense == THE_RISING_EDGE) && (enable == INT_2))
{
	MCUCSR |=(1<<6);
	GICR |=(1<<5);
}

	
}










/*test modules for the driver's APIs*/

/*
#include "../../ECUAL/LED Driver/led.h"
#include "../../ECUAL/BUTTON Driver/button.h"
#define NUMBER_OF_LEDS 3
uint8_t led_number;
int main(void)
{
	
    LED_init(0,PORT_A);
    LED_init(3,PORT_A);
    LED_init(7,PORT_A);
    BUTTON_init(2,PORT_D);
    sei();
    EnalbleExternalInterrupt(THE_RISING_EDGE , INT_0);

	while(1)
	{
		switch(led_number)
			{
				
				case 0:
				LED_off(0,PORT_A);
				LED_off(3,PORT_A);
				LED_off(7,PORT_A);
				break;
					
				case 1:
				LED_on(0,PORT_A);
				break;

				case 2:
				LED_on(3,PORT_A);
				break;

				case 3:
				LED_on(7,PORT_A);
				break;
					
				default:
				break;
			
			}		
		
	}
}



ISR(EXT_INT_0)
{
	if (led_number < NUMBER_OF_LEDS)
		{
			led_number++;
		}
		else
		{
			led_number=0;
		}
		
}
*/