/*
 * button.c
 *
 *  Created on: Sep 21, 2022
 *      Author: KAI
 */

#include "button.h"
#include "global.h"


int buttonsArr[BUTTONS_NUMBER] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

int KeyReg0[BUTTONS_NUMBER] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[BUTTONS_NUMBER] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[BUTTONS_NUMBER] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[BUTTONS_NUMBER] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress = 300;
int button_flag[BUTTONS_NUMBER] = {0,0,0};
int button_pressing[BUTTONS_NUMBER] = {0,0,0};

int isButtonPressed(int i){
	if (button_flag[i] == 1){
		button_flag[i] = 0;
		return 1;
	}
	return 0;

}

int isButtonLongPressed(int i){
	if (button_flag[i] == 1){
			return 1;
		}
	return 0;
}

void resetPressingState(int i){
	button_flag[i] = 0;
}

void subKeyProcess(int i){
	button_flag[i] = 1;
}

int isButtonReleased(int i){
	if(HAL_GPIO_ReadPin(GPIOA, buttonsArr[i]) == 1) return 1;
	else return 0;
}

void getKeyInput(){
	for(int i=0; i<BUTTONS_NUMBER; i++){
	  KeyReg0[i] = KeyReg1[i];
	  KeyReg1[i] = KeyReg2[i];
	  KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, buttonsArr[i]);
	  if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
		if (KeyReg2[i] != KeyReg3[i]){
		  KeyReg3[i] = KeyReg2[i];

		  if (KeyReg2[i] == PRESSED_STATE){
			subKeyProcess(i);
			TimeOutForKeyPress = 300;
		  }
		}else{
		   TimeOutForKeyPress--;
			if(TimeOutForKeyPress == 0){
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
				  }
				TimeOutForKeyPress = 500;
			}
		}
	  }
	}
}

