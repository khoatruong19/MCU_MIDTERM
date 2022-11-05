/*
 * fsm_blink_led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */


#include "fsm_blink_led.h"


void fsm_blink_led_run(){
	switch(LED_STATE){
		case LED_INIT:
			LED_STATE = LED_ON;
			setTimer0(50);
			break;
		case LED_ON:
			if(timer0_flag == 1){
				LED_STATE = LED_OFF;
				toggleRedLED();
				setTimer0(50);
			}
			break;
		case LED_OFF:
			if(timer0_flag == 1){
				LED_STATE = LED_ON;
				toggleRedLED();
				setTimer0(50);
			}
			break;
		default:
			break;
	}

}
