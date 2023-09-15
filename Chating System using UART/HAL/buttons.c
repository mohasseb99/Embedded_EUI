/*
 * buttons.c
 *
 *  Created on: Sep 5, 2023
 *      Author: mohas
 */

#include "buttons.h"
#include <stdint.h>
#include <stdbool.h>
#include "../MCAL/DIO.h"

void SW1_init(){
    DIO_Init(PORTF, PIN4, IN);
}

void SW2_init(){
    DIO_Init(PORTF, PIN0, IN);
}

uint8_t SW1_isPressed(){
    uint8_t pressed = 0;
    if(DIO_getPinValue(PORTF, PIN4) == 0){
        pressed = 1;
    }
    else{
        pressed = 0;
    }
    return pressed;
}

uint8_t SW2_isPressed(){
    uint8_t pressed = 0;
    if(DIO_getPinValue(PORTF, PIN0) == 0){
        pressed = 1;
    }
    else{
        pressed = 0;
    }
    return pressed;
}
