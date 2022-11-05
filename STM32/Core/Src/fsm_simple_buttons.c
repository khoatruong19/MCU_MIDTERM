/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */


#include "fsm_simple_buttons.h"


void fsm_simple_buttons_run(void) {
	switch(MODE) {
		case INIT:
			if(isButtonPressed(RESET_BUTTON) == 1){
					MODE = RESET_VALUE;
			}
			if(isButtonLongPressed(INC_BUTTON) == 1 ){
					MODE = INCREASE;
					setTimer2(300);
					value = (value + 1) % 10;
			}
			if(isButtonLongPressed(DEC_BUTTON) == 1 ){
					MODE = DECREASE;
					setTimer3(300);
					if(value >0) value--;
					else value = MAX_VALUE;
			}
			break;
		case RESET_VALUE:
			value = 0;
			MODE = INIT;
			break;
		case INCREASE:
			if(timer2_flag == 1){
				if(isButtonReleased(INC_BUTTON) != 1){
					value = (value + 1) % 10;
					setTimer2(100);
					 MODE = INCREASING;
				}
				else {
					resetPressingState(INC_BUTTON);
					MODE= INIT;
				}
			}
			if(isButtonReleased(INC_BUTTON) == 1) {
				resetPressingState(INC_BUTTON);
				MODE= INIT;
			}
			break;
		case INCREASING:
			 if(timer2_flag == 1){
				  if(isButtonReleased(INC_BUTTON) != 1){
					  value = (value + 1) % 10;
					  setTimer2(100);
				  }
			  }
			 if(isButtonReleased(INC_BUTTON) == 1){
				 resetPressingState(INC_BUTTON);
				 MODE= INIT;
			 }
			break;
		case DECREASE:
				if(timer3_flag == 1){
					if(isButtonReleased(DEC_BUTTON) != 1){
						if(value >0) value--;
						else value = MAX_VALUE;
						setTimer3(100);
						 MODE = DECREASING;
					}
					else {
						resetPressingState(DEC_BUTTON);
						MODE= INIT;
					}
				}
				if(isButtonReleased(DEC_BUTTON) == 1) {
					resetPressingState(DEC_BUTTON);
					MODE= INIT;
				}
				break;
		case DECREASING:
			if(timer3_flag == 1){
				  if(isButtonReleased(DEC_BUTTON) != 1){
					  if(value >0) value--;
					  else value = MAX_VALUE;
					  setTimer3(100);
				  }
			  }
			 if(isButtonReleased(DEC_BUTTON) == 1){
				 resetPressingState(DEC_BUTTON);
				 MODE= INIT;
			 }
				break;
		default:
			break;
	}
}
