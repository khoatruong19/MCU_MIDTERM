/*
 * fsm_10s_over.c
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */

#include "fsm_10s_over.h"


void fsm_10s_over_run() {
	switch(MODE){
		case INIT:
			if(timer4_flag == 1) {
				counterTo10++;
					if(counterTo10 > 10){
						previousValue = value;
						MODE = SLEEP;
						value--;
					}
					setTimer4(100);
				}
			break;
		case SLEEP:
			if(timer4_flag == 1) {
				if(value > 0) value--;
				setTimer4(100);
			}
			if(isButtonPressed(INC_BUTTON) == 1 || isButtonPressed(DEC_BUTTON) == 1){
				MODE = WAKE_UP;
			}

			break;
		case WAKE_UP:
			resetCounterTo10();
			setValues();
			setTimer4(100);
			break;
		default:
			break;
	}
}


