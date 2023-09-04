/*
 * GPTM.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mohas
 */
#include "../INC/GPTM.h"
#include "../INC/tm4c123gh6pm.h"
#include "../INC/bitwise_operation.h"

void GPTM_init(unsigned char timer, unsigned char timer_bit, unsigned char mode, unsigned char counting, unsigned long tick, unsigned long prescaler){
    if (timer == TIMER0){
        setBit(NVIC_EN0_R, 19);

        setBit(SYSCTL_RCGCTIMER_R, 0); //RCGCTIMER = set pin 0 to enable timer 0

        clearBit(TIMER0_CTL_R, 0);     //clear pin 0 to disable timer A

        setBit(TIMER0_CTL_R, 1);       //set 1 to stop counting while counting

        TIMER0_CFG_R = TIMER0_CFG_R & 0xF8 | 0x04; //0:d2 100 to select 16 bit mode

        /*
        clearBit(TIMER0_CFG_R, 0);
        clearBit(TIMER0_CFG_R, 1);
        setBit(TIMER0_CFG_R, 2);
*/

        clearBit(TIMER0_TAMR_R, 4); //D4 0 to get  count down mode

        TIMER0_TAMR_R = TIMER0_TAMR_R & 0xFC | 0x2; //d0:d1 10 to select periodic mode
        /*clearBit(TIMER0_TAMR_R, 0);
        setBit(TIMER0_TAMR_R, 1);
*/


        TIMER0_TAILR_R = tick; //GPTMTAILR is set to 64000
        TIMER0_TAPR_R = prescaler; //TAPR WILL BE 125 prescaler

        setBit(TIMER0_ICR_R, 0);//clear flag bit 0 from icr register


        setBit(TIMER0_IMR_R, 0); //enable the interrupt
        setBit(TIMER0_CTL_R, 0); //enable timer

    }

    if(timer == TIMER2){
        setBit(NVIC_EN3_R, 2);  // to enable interrupt of timer

        setBit(SYSCTL_RCGCWTIMER_R, 2);   // enable timer clock

        clearBit(WTIMER2_CTL_R, 0);   // to disable timer

        setBit(WTIMER2_CTL_R, 1);   // to stop counting while debugging

        WTIMER2_CFG_R =  WTIMER2_CFG_R & 0xF8 | 0x04;  //to select 32 bit mode


        WTIMER2_TAMR_R = WTIMER2_TAMR_R & 0xFC | 0x3;
        setBit(WTIMER2_TAMR_R, 2);
        setBit(WTIMER2_TAMR_R, 4);

        WTIMER2_TAILR_R = tick; //GPTMTAILR is set to 64000

        setBit(WTIMER2_ICR_R, 2);//clear flag bit 0 from icr register


        setBit(WTIMER2_IMR_R, 2); //enable the interrupt
        setBit(WTIMER2_CTL_R, 0); //enable timer
    }




}

void delay_periodic(){
    long i = 0;
    while(getBit(TIMER0_RIS_R, 0) != 1){
        i++;
    }
    clearBit(TIMER0_ICR_R, 0);

}

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
