/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: WELCOME
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define RESET_BUTTON 0
#define INC_BUTTON 1
#define DEC_BUTTON 2

#define MAX_VALUE 9

enum ModeState {INIT,RESET_VALUE,INCREASE, DECREASE, INCREASING,DECREASING, SLEEP, WAKE_UP};

enum LedState{LED_INIT,LED_ON, LED_OFF};

extern enum ModeState MODE;
extern enum LedState LED_STATE;

extern int value;
extern int previousValue;
extern int counterTo10;
extern int firstLoop;

void setValues(void);

void resetCounterTo10(void);

#endif /* INC_GLOBAL_H_ */
