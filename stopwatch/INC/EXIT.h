/*
 * EXIT.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mohas
 */

#ifndef INC_EXIT_H_
#define INC_EXIT_H_


#define RISING_EDGE 1
#define FALLING_EDGE 0
#define BOTH_EDGES 2

#define HIGH_LEVEL 1
#define LOW_LEVEL 0

#define EDGE_MODE 1
#define LEVEL_MODE 0

void GPIOE_Handler(void);
void INT_PIN_INIT(unsigned char portNum, unsigned char pinNum, unsigned char mode, unsigned char sense);
void INT_PIN_CLEAR (unsigned char portNum, unsigned char pinNum);
unsigned char INT_PIN_CHECK (unsigned char portNum, unsigned char pinNum);

#endif /* INC_EXIT_H_ */
