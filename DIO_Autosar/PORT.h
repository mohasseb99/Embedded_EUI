/*
 * PORT.h
 *
 *  Created on: Oct 15, 2023
 *      Author: mohas
 */

#ifndef MCAL_PORT_H_
#define MCAL_PORT_H_

#include <stdint.h>

#define PORTA 0U
#define PORTB 1U
#define PORTC 2U
#define PORTD 3U
#define PORTE 4U
#define PORTF 5U

#define UNLOCK 0x4C4F434BU

#define PIN0 0U
#define PIN1 1U
#define PIN2 2U
#define PIN3 3U
#define PIN4 4U
#define PIN5 5U
#define PIN6 6U
#define PIN7 7U

#define IN 0U
#define OUT 1U

void DIO_Init(uint8_t portNum, uint8_t pinNum, uint8_t dir);

#endif /* MCAL_PORT_H_ */
