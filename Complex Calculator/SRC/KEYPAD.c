/*
 * KEYPAD.c
 *
 *  Created on: Aug 19, 2023
 *      Author: mohas
 */

#include "../INC/KEYPAD.h"
#include "../INC/DIO.h"
#include "../INC/Delay.h"


unsigned char symbol[ROWS_SIZE][COLS_SIZE] = {{'1', '2', '3', '+'},
                                              {'4', '5', '6', '-'},
                                              {'7', '8', '9', '*'},
                                              {'.', '0', '=', '/'}};

extern unsigned char pressed;

void KEYPAD_INIT(void){
#ifdef KEYPAD_4X4
    DIO_Init(ROWS_PORT, R1, IN);
    DIO_Init(ROWS_PORT, R2, IN);
    DIO_Init(ROWS_PORT, R3, IN);
    DIO_Init(ROWS_PORT, R4, IN);

    DIO_Init(COLS_PORT, C1, OUT);
    DIO_Init(COLS_PORT, C2, OUT);
    DIO_Init(COLS_PORT, C3, OUT);
    DIO_Init(COLS_PORT, C4, OUT);

    DIO_WritePin(COLS_PORT, C1, 1);
    DIO_WritePin(COLS_PORT, C2, 1);
    DIO_WritePin(COLS_PORT, C3, 1);
    DIO_WritePin(COLS_PORT, C4, 1);

#endif
}

unsigned char KEYPAD_getKey(void){
    long i = 0, j = 0;
    while(1){
        for(i = 0; i < 4; i++){
            DIO_WritePort(COLS_PORT, ( (DIO_getPortValue(COLS_PORT) & 0x0F ) | 0xF0) & ~(1<<i+4) );
            for(j = 0; j < 4; j++){
                if(DIO_getPinValue(ROWS_PORT, j) == 0){
                    Delay(150);
                    while(DIO_getPinValue(ROWS_PORT, j) == 0){}
                    return symbol[j][i];
                }
            }
        }
    }
}

unsigned char KEYPAD_getKeyInt(void){
    long i = 0, j= 0;
    while(1){
        for(i = 0; i < 4; i++){
            DIO_WritePort(COLS_PORT, ( (DIO_getPortValue(COLS_PORT) & 0x0F ) | 0xF0) & ~(1<<i+4) );
            if(pressed != 5){
                for(j = 0; j < 600000; j++){}
                unsigned char pre = pressed;
                pressed = 5;
                while(DIO_getPinValue(ROWS_PORT, pre) == 0){}
                return symbol[pre][i];
            }
        }
    }
}


