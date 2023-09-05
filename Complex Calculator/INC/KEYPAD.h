/*
 * KEYPAD.h
 *
 *  Created on: Aug 19, 2023
 *      Author: mohas
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#define ROWS_SIZE 4
#define COLS_SIZE 4


#define KEYPAD_4X4

#define ROWS_PORT PORTE
#define COLS_PORT PORTC

#define R1 PIN0
#define R2 PIN1
#define R3 PIN2
#define R4 PIN3

#define C1 PIN4
#define C2 PIN5
#define C3 PIN6
#define C4 PIN7


void KEYPAD_INIT(void);
unsigned char KEYPAD_getKey(void);
unsigned char KEYPAD_getKeyInt(void);

#endif /* INC_KEYPAD_H_ */
