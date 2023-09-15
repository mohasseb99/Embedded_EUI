/*
 * TIVA.h
 *
 *  Created on: Sep 3, 2023
 *      Author: mohas
 */

#ifndef HAL_TIVA_H_
#define HAL_TIVA_H_


#define BUFFER_SIZE_TIVA 15

void connect_tiva(void);
void send_tiva_char(unsigned char data);
void stop_tiva();
void start_tiva();


#endif /* HAL_TIVA_H_ */
