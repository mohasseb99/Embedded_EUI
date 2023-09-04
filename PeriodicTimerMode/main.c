#include "INC/DIO.h"
#include "INC/EXIT.h"
#include "INC/GPTM.h"
#include "INC/tm4c123gh6pm.h"
#include "INC/bitwise_operation.h"

int main(void)
{
    DIO_Init(PORTF, PIN1, OUT);
    DIO_Init(PORTF, PIN2, OUT);
    DIO_Init(PORTF, PIN3, OUT);
    DIO_WritePin(PORTF, PIN1, 0);
    DIO_WritePin(PORTF, PIN2, 0);
    DIO_WritePin(PORTF, PIN3, 0);
    GPTM_init(TIMER0, TIMERA, PERIODIC, COUNT_DOWN, 31249, 255);

    while(1){
    }
    return 0;
}

void TIMER0A_Handler(void){
    DIO_WritePin(PORTF, PIN1, DIO_getPinValue(PORTF, PIN1) ^ 1);
    DIO_WritePin(PORTF, PIN2, DIO_getPinValue(PORTF, PIN2) ^ 1);
    DIO_WritePin(PORTF, PIN3, DIO_getPinValue(PORTF, PIN3) ^ 1);

    setBit(TIMER0_ICR_R, 0);
}
