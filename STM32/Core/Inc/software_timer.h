/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2022
 *      Author: WELCOME
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

int timer0_flag;
int timer1_flag;
int timer2_flag;
int timer3_flag;
int timer4_flag;
int timer5_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
