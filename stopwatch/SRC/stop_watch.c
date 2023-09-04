/*
 * stop_watch.c
 *
 *  Created on: Aug 24, 2023
 *      Author: mohas
 */

#include "../INC/LCD.h"
#include "../INC/stop_watch.h"
unsigned long min=0,sec=0;
unsigned long min_lap = 0, sec_lap = 0;

static void adjust(){
    if (sec>59){
        sec=0;
        min++;
    }
    if (min>59){
        sec=0;
        min=0;
    }
}

void print_time(){
    long i = 0;
    for(i = 0; i < 1200000; i++){}
    write_command(LCD_CLEAR_COMMAND);
    adjust();
    write_data(min/10 + '0');
    write_data(min%10+'0');
    write_data(':');
    write_data(sec/10 + '0');
    write_data(sec%10+'0');

    write_data(' ');
    write_data(' ');
    write_data(' ');
    write_data(' ');
    if(sec_lap != 0 || min_lap!=0){
        write_data(min_lap/10 + '0');
        write_data(min_lap%10+'0');
        write_data(':');
        write_data(sec_lap/10 + '0');
        write_data(sec_lap%10+'0');
    }
}
