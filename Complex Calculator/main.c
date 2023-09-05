#include "INC/lcd.h"
#include "INC/KEYPAD.h"
#include "INC/EXIT.h"
#include "INC/tm4c123gh6pm.h"
#include "INC/calculator.h"
#include <stdio.h>

extern long result;
extern unsigned char st_wrongSyntax;
extern unsigned char st_divideZero;

int main(void)
{
    LCD_INIT();
    KEYPAD_INIT();
    write_string(" Calculator App Mohasseb   Monem");
    unsigned long i = 0;
    for(i = 0; i < 2000000; i++){}
    write_command(LCD_CLEAR_COMMAND);
    clear_calculator();

    while(1){
        unsigned char val = KEYPAD_getKey();
        write_data(val);
        if('=' == val){
            calculator(val);
            if(st_divideZero == 1){
                write_command(LCD_CLEAR_COMMAND);
                write_string(" Divide By Zero ");
                for(i = 0; i < 2000000; i++){}
                write_command(LCD_CLEAR_COMMAND);
            }
            else if(st_wrongSyntax == 1){
                write_command(LCD_CLEAR_COMMAND);
                write_string("  Wrong Syntax  ");
                for(i = 0; i < 2000000; i++){}
                write_command(LCD_CLEAR_COMMAND);
            }
            else{
                write_num(result);
                for(i = 0; i < 7000000; i++){}
                write_command(LCD_CLEAR_COMMAND);
            }
            clear_calculator();
        }
        else{
            calculator(val);
        }
    }
}
