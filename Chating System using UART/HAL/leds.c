#include "leds.h"
#include "../MCAL/DIO.h"

void initialize_leds(){
    DIO_Init(PORTF, PIN1, OUT);
    DIO_Init(PORTF, PIN2, OUT);
    DIO_Init(PORTF, PIN3, OUT);
    DIO_WritePin(PORTF, PIN1, 0);
    DIO_WritePin(PORTF, PIN2, 0);
    DIO_WritePin(PORTF, PIN3, 0);
}

void turn_on_White(){
    DIO_WritePin(PORTF, PIN1, 1);
    DIO_WritePin(PORTF, PIN2, 1);
    DIO_WritePin(PORTF, PIN3, 1);
}

void turn_on_Red(){
    DIO_WritePin(PORTF, PIN1, 1);
    DIO_WritePin(PORTF, PIN2, 0);
    DIO_WritePin(PORTF, PIN3, 0);
}

void turn_on_Blue(){
    DIO_WritePin(PORTF, PIN1, 0);
    DIO_WritePin(PORTF, PIN2, 1);
    DIO_WritePin(PORTF, PIN3, 0);
}
