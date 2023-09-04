/*
 * systick.h
 *
 *  Created on: Aug 24, 2023
 *      Author: mohas
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


#define TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK 16000
#define TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK_DIV_4 4000

#define TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK 16
#define TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK_DIV_4 4

void delay_ms(unsigned long time);
void delay_MS(unsigned long time);
void SYSTICK_clear(void);
void SYSTICK_INT_INIT_ms (unsigned long time);
void SYSTICK_INT_INIT_MS (unsigned long time);
void toggle_enable();


#define SYSTEM_CLOCK 1
#define SYSTEM_CLOCK_DIV_4 0
#define clock SYSTEM_CLOCK_DIV_4

#endif /* SYSTICK_H_ */
