/*
 * LCD.c
 *
 *  Created on: Aug 18, 2023
 *      Author: mohas
 */

#include "../INC/DIO.h"
#include "../INC/LCD.h"
#include "../INC/bitwise_operation.h"


void LCD_INIT(void){
#if(LCD_MODE == 4)
    DIO_Init(PORT_DATA, DATA4, OUT);
    DIO_Init(PORT_DATA, DATA5, OUT);
    DIO_Init(PORT_DATA, DATA6, OUT);
    DIO_Init(PORT_DATA, DATA7, OUT);

    DIO_Init(PORT_CONTROL, RS_PIN, OUT);
    DIO_Init(PORT_CONTROL, RW_PIN, OUT);
    DIO_Init(PORT_CONTROL, EN_PIN, OUT);

    DIO_WritePin(PORT_CONTROL, RW_PIN, 0);
    DIO_WritePin(PORT_CONTROL, EN_PIN, 1);
    DIO_WritePin(PORT_CONTROL, RS_PIN, 0);

    write_command(LCD_TWO_LINES_FOUR_BITS_MODE);
    write_command(LCD_CURSOR_OFF);
    write_command(LCD_CLEAR_COMMAND);

#elif (LCD_MODE == 8)

#endif

}


void write_command(unsigned char command){
    long i = 0;
    DIO_WritePin(PORT_CONTROL, RS_PIN, 0);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 1);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_DATA, DATA4, getBit(command,4));
    DIO_WritePin(PORT_DATA, DATA5, getBit(command,5));
    DIO_WritePin(PORT_DATA, DATA6, getBit(command,6));
    DIO_WritePin(PORT_DATA, DATA7, getBit(command,7));
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 0);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 1);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_DATA, DATA4, getBit(command,0));
    DIO_WritePin(PORT_DATA, DATA5, getBit(command,1));
    DIO_WritePin(PORT_DATA, DATA6, getBit(command,2));
    DIO_WritePin(PORT_DATA, DATA7, getBit(command,3));
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 0);
    for(i = 0; i < 5000; i++){}
}

void write_data(unsigned char data){
    long i = 0;
    DIO_WritePin(PORT_CONTROL, RS_PIN, 1);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 1);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_DATA, DATA4, getBit(data,4));
    DIO_WritePin(PORT_DATA, DATA5, getBit(data,5));
    DIO_WritePin(PORT_DATA, DATA6, getBit(data,6));
    DIO_WritePin(PORT_DATA, DATA7, getBit(data,7));
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 0);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 1);
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_DATA, DATA4, getBit(data,0));
    DIO_WritePin(PORT_DATA, DATA5, getBit(data,1));
    DIO_WritePin(PORT_DATA, DATA6, getBit(data,2));
    DIO_WritePin(PORT_DATA, DATA7, getBit(data,3));
    for(i = 0; i < 5000; i++){}
    DIO_WritePin(PORT_CONTROL, EN_PIN, 0);
    for(i = 0; i < 5000; i++){}
}


void write_string(char* str){
    long i = 0;
    while(str[i] != '\0'){
        write_data(str[i]);
        i++;
        if(i == 16){
            write_command(LCD_GO_TO_SECOND_LINE);
        }
    }
}

static int countDigits(long num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

void write_num(long num){
    if(num == 0){
        write_string("0");
    }
    else{
        char buffer[10];
        int numDigits = countDigits(num);

        if (num < 0) {  /* Handle negative numbers */
            num = num * -1;
            write_data('-');     /* if number less than zero we write - */
        }

        buffer[numDigits] = '\0';

        /* Convert each digit to its ASCII representation and store in the buffer */
        int i;
        for (i = numDigits - 1; i >= 0; i--) {
            buffer[i] = '0' + (num % 10);
            num /= 10;
        }

        write_string(buffer);
    }
}
