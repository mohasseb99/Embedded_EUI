
#include "PORT.h"
#include "../tm4c123gh6pm.h"
#include "../bitwise_operation.h"

void DIO_Init(uint8_t portNum, uint8_t pinNum, uint8_t dir)
{
    SYSCTL_RCGCGPIO_R |= (1<<portNum);
    while(getBit(SYSCTL_RCGCGPIO_R, portNum) != 1){}

    switch(portNum){
    case PORTA:
        if(dir == IN){
            clearBit(GPIO_PORTA_DIR_R, pinNum);
            setBit(GPIO_PORTA_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTA_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTA_DEN_R, pinNum);
        break;
    case PORTB:
        if(dir == IN){
            clearBit(GPIO_PORTB_DIR_R, pinNum);
            setBit(GPIO_PORTB_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTB_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTB_DEN_R, pinNum);
        break;
    case PORTC:
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTC_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTC_DIR_R, pinNum);
            setBit(GPIO_PORTC_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTC_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTC_DEN_R, pinNum);
        break;
    case PORTD:
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTD_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTD_DIR_R, pinNum);
            setBit(GPIO_PORTD_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTD_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTD_DEN_R, pinNum);
        break;
    case PORTE:
        if(dir == IN){
            clearBit(GPIO_PORTE_DIR_R, pinNum);
            setBit(GPIO_PORTE_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTE_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTE_DEN_R, pinNum);
        break;
    case PORTF:
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTF_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTF_DIR_R, pinNum);
            setBit(GPIO_PORTF_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTF_DIR_R, pinNum);
        }
        else{
            /* MISRA */
        }
        setBit(GPIO_PORTF_DEN_R, pinNum);
        break;
    default:
        break;
    }
}
