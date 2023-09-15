/*
 * PC.h
 *
 *  Created on: Sep 3, 2023
 *      Author: mohas
 */

#ifndef HAL_PC_H_
#define HAL_PC_H_

#define BUFFER_SIZE_PC 15

void connect_pc(void);
void send_pc_char(unsigned char data);
void stop_pc();
void start_pc();

#endif /* HAL_PC_H_ */
