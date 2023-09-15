/*
 * PC.c
 *
 *  Created on: Sep 3, 2023
 *      Author: mohas
 */


#include "PC.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "../tm4c123gh6pm.h"

void UART0_Handler_PC_Rec(void);
uint8_t rec_buffer_pc[BUFFER_SIZE_PC];
uint8_t rec_len_pc;
uint8_t recevied_pc = 0;
uint8_t first_int = 1;
uint8_t pc_busy = 0;

void connect_pc(void){
    // Enable the UART0 module.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    // Wait for the UART0 module to be ready.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)){}
    // Initialize the UART
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTIntRegister(UART0_BASE, UART0_Handler_PC_Rec);
    UARTIntEnable(UART0_BASE, UART_INT_RX);
    UARTFIFODisable(UART0_BASE);

    // Initialize Pins of UART0 PA0 - PA1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    //UARTEnable(UART0_BASE);

}

void send_pc_char(unsigned char data){
    UARTCharPut(UART0_BASE, data);
}


void stop_pc(){
    //enable_flag = 0;
    UARTIntDisable(UART0_BASE, UART_INT_RX);
    //UARTDisable(UART0_BASE);
}


void start_pc(){
    //enable_flag = 1;
    UARTIntEnable(UART0_BASE, UART_INT_RX);
    //UARTEnable(UART0_BASE);

}


void UART0_Handler_PC_Rec(void){
    /*uint32_t i = 6000;
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1), 0);
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_2), 0);
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_3), (GPIO_PIN_3));
    for(i = 0; i < 5000000; i++){}
    */
    uint32_t stat = UARTIntStatus(UART0_BASE, true);
    UARTIntClear(UART0_BASE, stat);
    if(first_int == 0){
        pc_busy = 1;
        uint8_t recieved = 0;
        recieved = UARTCharGet(UART0_BASE);
        send_pc_char(recieved);
        if(recieved == 13){   /* The ASCII code for enter key is 13 */
            recevied_pc = 1;
            rec_buffer_pc[rec_len_pc] = recieved;
            rec_len_pc++;
            send_pc_char('\n');
            pc_busy = 0;
        }
        else if(recieved == 127 && rec_len_pc > 0){   /* The ASCII code for backspace is 127 */
            rec_len_pc--;
        }
        else{
            if(rec_len_pc < BUFFER_SIZE_PC - 1){
                rec_buffer_pc[rec_len_pc] = recieved;
                rec_len_pc++;
            }
        }
    }
    else{
        uint8_t recieved = 0;
        recieved = UARTCharGet(UART0_BASE);
        first_int = 0;
    }
}
