/*
 * systick.c
 *
 *  Created on: Aug 24, 2023
 *      Author: mohas
 */


#include "../INC/systick.h"
#include "../INC/tm4c123gh6pm.h"
#include "../INC/bitwise_operation.h"


void delay_ms(unsigned long time){
    clearBit(NVIC_ST_CTRL_R, 0);        // disable counter

#if (clock == SYSTEM_CLOCK)
        setBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock
        NVIC_ST_RELOAD_R = time * TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK;         // setting reload value as we will give input time
#elif(clock == SYSTEM_CLOCK_DIV_4)
        clearBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock / 4
        NVIC_ST_RELOAD_R = time * TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK_DIV_4;         // setting reload value as we will give input time
#endif

    setBit(NVIC_ST_CTRL_R, 0);          // enable timer
    while(!(getBit(NVIC_ST_CTRL_R, 16) )); /* Wait for timer to reach 0 and flag is raised */
    NVIC_ST_CURRENT_R = 0;          // clear flag
    clearBit(NVIC_ST_CTRL_R, 0);    // disable timer
}

void delay_MS(unsigned long time){
    clearBit(NVIC_ST_CTRL_R, 0);        // disable counter

#if (clock == SYSTEM_CLOCK)
        setBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock
        NVIC_ST_RELOAD_R = time * TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK;         // setting reload value as we will give input time
#elif (clock == SYSTEM_CLOCK_DIV_4)
        clearBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock / 4
        NVIC_ST_RELOAD_R = time * TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK_DIV_4;         // setting reload value as we will give input time
#endif

    setBit(NVIC_ST_CTRL_R, 0);          // enable timer
    while(!(getBit(NVIC_ST_CTRL_R, 16) )); /* Wait for timer to reach 0 and flag is raised */
    NVIC_ST_CURRENT_R = 0;          // clear flag
    clearBit(NVIC_ST_CTRL_R, 0);    // disable timer
}

void SYSTICK_INT_INIT_ms (unsigned long time){
    clearBit(NVIC_ST_CTRL_R, 0);        // disable counter

#if (clock == SYSTEM_CLOCK)
        setBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock
        NVIC_ST_RELOAD_R = time * TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK;         // setting reload value as we will give input time
#elif (clock == SYSTEM_CLOCK_DIV_4)
        clearBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock / 4
        NVIC_ST_RELOAD_R = time * TICKS_PER_MILLI_SECONDS_SYSTEM_CLOCK_DIV_4;         // setting reload value as we will give input time
#endif
    setBit(NVIC_ST_CTRL_R, 1);          // setting INT to enable
    setBit(NVIC_ST_CTRL_R, 0);          // enable timer
}

void SYSTICK_INT_INIT_MS (unsigned long time){
    clearBit(NVIC_ST_CTRL_R, 0);        // disable counter

#if (clock == SYSTEM_CLOCK)
        setBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock
        NVIC_ST_RELOAD_R = time * TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK;         // setting reload value as we will give input time
#elif (clock == SYSTEM_CLOCK_DIV_4)
        clearBit(NVIC_ST_CTRL_R, 2);          // setting clock is system clock / 4
        NVIC_ST_RELOAD_R = time * TICKS_PER_MICRO_SECONDS_SYSTEM_CLOCK_DIV_4;         // setting reload value as we will give input time
#endif
    setBit(NVIC_ST_CTRL_R, 1);          // setting INT to enable
    setBit(NVIC_ST_CTRL_R, 0);          // enable timer
}

void SYSTICK_clear(void){
    NVIC_ST_CURRENT_R = 0;
}

void toggle_enable(){
    Toggle_Bit(NVIC_ST_CTRL_R, 0);
}
