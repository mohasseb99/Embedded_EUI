/*
 * EXIT.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mohas
 */


#include "../INC/DIO.h"
#include "../INC/EXIT.h"
#include "../INC/LCD.h"
#include "../INC/tm4c123gh6pm.h"
#include "../INC/bitwise_operation.h"

unsigned char pressed = 5;



void INT_PIN_INIT(unsigned char portNum, unsigned char pinNum, unsigned char mode, unsigned char sense){
    if(portNum == PORTA){

    }
    else if(portNum == PORTB){

    }
    else if(portNum == PORTC){

    }
    else if(portNum == PORTD){

    }
    else if(portNum == PORTE){
        if(mode == EDGE_MODE){
            GPIO_PORTE_IS_R &= ~(1<<pinNum);
            if(sense == BOTH_EDGES){
                GPIO_PORTE_IBE_R |= (1<<pinNum);
            }
            else if(sense == FALLING_EDGE){
                GPIO_PORTE_IBE_R &= ~(1<<pinNum);
                GPIO_PORTE_IEV_R &= ~(1<<pinNum);
            }
            else if(sense == RISING_EDGE){
                GPIO_PORTE_IBE_R &= ~(1<<pinNum);
                GPIO_PORTE_IEV_R |= (1<<pinNum);
            }
        }
        else if(mode == LEVEL_MODE){
            GPIO_PORTE_IS_R |= (1<<pinNum);
            if(sense == LOW_LEVEL){
                GPIO_PORTE_IBE_R &= ~(1<<pinNum);
                GPIO_PORTE_IEV_R &= ~(1<<pinNum);
            }
            else if(sense == HIGH_LEVEL){
                GPIO_PORTE_IBE_R &= ~(1<<pinNum);
                GPIO_PORTE_IEV_R |= (1<<pinNum);
            }
        }
        GPIO_PORTE_ICR_R |= (1<<pinNum);
        GPIO_PORTE_IM_R |= (1<<pinNum);

        NVIC_EN0_R |= 1 << 4;
        NVIC_PRI1_R |= 3 << 5;
    }
    else if(portNum == PORTF){

    }

}

void INT_PIN_CLEAR (unsigned char portNum, unsigned char pinNum){
    if(portNum == PORTA){

    }
    else if(portNum == PORTB){

    }
    else if(portNum == PORTC){

    }
    else if(portNum == PORTD){

    }
    else if(portNum == PORTE){
        GPIO_PORTE_ICR_R |= (1<<pinNum);
    }
    else if(portNum == PORTF){

    }
}
unsigned char INT_PIN_CHECK (unsigned char portNum, unsigned char pinNum){
    unsigned char value;
    if(portNum == PORTA){

    }
    else if(portNum == PORTB){

    }
    else if(portNum == PORTC){

    }
    else if(portNum == PORTD){

    }
    else if(portNum == PORTE){
        value = getBit(GPIO_PORTE_MIS_R, pinNum);
    }
    else if(portNum == PORTF){

    }
    return value;
}

void GPIOE_Handler(void){
    if(INT_PIN_CHECK(PORTE, PIN0)){
        pressed = 0;
        INT_PIN_CLEAR(PORTE, PIN0);
    }
    else if(INT_PIN_CHECK(PORTE, PIN1)){
        pressed = 1;
        INT_PIN_CLEAR(PORTE, PIN1);
    }
    else if(INT_PIN_CHECK(PORTE, PIN2)){
        pressed = 2;
        INT_PIN_CLEAR(PORTE, PIN2);
    }
    else if(INT_PIN_CHECK(PORTE, PIN3)){
        pressed = 3;
        INT_PIN_CLEAR(PORTE, PIN3);
    }
}
