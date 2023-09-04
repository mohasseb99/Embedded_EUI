/*
 * GPTM.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mohas
 */

#ifndef INC_GPTM_H_
#define INC_GPTM_H_



#define TIMER0 0
#define TIMER2 2
#define TIMERA 0
#define TIMERB 1


#define PERIODIC 1
#define ONE_SHOT 0
#define CAPTURE 2

#define COUNT_UP 1
#define COUNT_DOWN 0


void GPTM_init(unsigned char timer, unsigned char timer_bit, unsigned char mode, unsigned char counting, unsigned long tick, unsigned long prescaler);


#endif /* INC_GPTM_H_ */

/*
RCGCTIMER = set pin 0 to enable timer 0
GPTMCTL clear pin 0 to disable timer a
gptmcfg d0:d2 100 to select 16 bit mode
gptmtamr d0:d1 10 to select periodic mode and D4 0 to get  count down mode
GPTMTAILR is set to 64000
TAPR WILL BE 125 prescaler
clear flag bit 0 from icr register
enabel timer
check bin 0 in ris to check flag*/
