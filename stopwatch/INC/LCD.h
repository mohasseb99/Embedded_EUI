/*
 * LCD.h
 *
 *  Created on: Aug 18, 2023
 *      Author: mohas
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "DIO.h"




#define PORT_DATA PORTB
#define DATA4 PIN4
#define DATA5 PIN5
#define DATA6 PIN6
#define DATA7 PIN7


#define PORT_CONTROL PORTB
#define RS_PIN PIN0
#define RW_PIN PIN1
#define EN_PIN PIN2


#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
#define LCD_GO_TO_SECOND_LINE                0xC0

#define LCD_MODE   4



void LCD_INIT(void);
void write_command(unsigned char command);
void write_data(unsigned char data);
void write_string(const char* str);


#endif /* INC_LCD_H_ */

//Data PB4:PB7 orange-red
// ground GND Black
// Vcc 3.3 brown
// register select PB0 purple
// read/write PB1 blue
// enable PB2 yellow
// v0 pot green
// A red
// k orange
