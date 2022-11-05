/*
 * button.h
 *
 *  Created on: Sep 21, 2022
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"


#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define BUTTONS_NUMBER 3

int isButtonPressed(int i);

int isButtonLongPressed(int i);

void resetPressingState(int i);

void getKeyInput();

int isButtonReleased(int i);

#endif /* INC_BUTTON_H_ */
