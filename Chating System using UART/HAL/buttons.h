/*
 * buttons.h
 *
 *  Created on: Sep 5, 2023
 *      Author: mohas
 */

#ifndef HAL_BUTTONS_H_
#define HAL_BUTTONS_H_

#include <stdint.h>

void SW1_init();
void SW2_init();

uint8_t SW1_isPressed();
uint8_t SW2_isPressed();

#endif /* HAL_BUTTONS_H_ */
