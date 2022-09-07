/*
 * HELP_Function.h
 *
 * Created: 9/3/2022 2:13:53 AM
 *  Author: Salem Elfaidy
 */ 


#ifndef HELP_FUNCTION_H_
#define HELP_FUNCTION_H_


void interruputOperation(void);
void ledOnFunction(uint8_t led1,uint8_t led2);
void ledToggleFunction(uint8_t led1,uint8_t led2);
void initCarsLeds(uint8_t led1,uint8_t led2,uint8_t led3);
void initPedestrianLeds(uint8_t led1,uint8_t led2,uint8_t led3);
void ledOffFunction(uint8_t led1,uint8_t led2,uint8_t led3,uint8_t led4);


#endif