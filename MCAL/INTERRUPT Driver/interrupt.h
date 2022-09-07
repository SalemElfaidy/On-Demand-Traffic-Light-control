/*
 * interrupt.h
 *
 * Created: 8/28/2022 10:31:22 PM
 *  Author: Salem Elfaidy
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>

/*External interrupts vectors*/
/*External interrupts request 0*/
#define EXT_INT_0 __vector_1
/*External interrupts request 1*/
#define EXT_INT_1 __vector_2
/*External interrupts request 2*/
#define EXT_INT_2 __vector_3


/*Set Global interrupts (set I bit in status register*/
#define sei() __asm__ __volatile__("sei" ::: "memory")

/*Clear Global interrupts (clear I bit in status register*/
#define cli() __asm__ __volatile__("cli" ::: "memory")

/*ISR Definition*/
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


/*set external interrupt you want*/
typedef enum InterruptEnable
{
	INT_0,INT_1,INT_2
}InterruptEnable;


/*sense of external interrupt*/
typedef enum InterruptSense
{
THE_LOW_LEVEL,ANY_LOGICAL_CHANGE,THE_FALLING_EDGE,THE_RISING_EDGE	
}interruptSense;


/*in this function you will send interrupt sense Identify any external interrupt*/
void EnalbleExternalInterrupt(interruptSense sense,InterruptEnable enable);


#endif 