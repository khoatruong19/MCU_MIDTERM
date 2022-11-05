/*
 * global.c
 *
 *  Created on: Nov 2, 2022
 *      Author: WELCOME
 */


#include "global.h"



enum ModeState MODE;
enum LedState LED_STATE;

int value = 0;

int previousValue = 0;

int counterTo10 = 0;

int firstLoop = 0;

void setValues(void){
	value = previousValue;
	MODE = INIT;
}

void resetCounterTo10(){
	counterTo10 = 0;
}
