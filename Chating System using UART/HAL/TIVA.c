/*
 * PC.c
 *
 *  Created on: Sep 3, 2023
 *      Author: mohas
 */


#include "TIVA.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"


void UART5_Handler_TIVA_Rec(void);
uint8_t rec_buffer_tiva[BUFFER_SIZE_TIVA];
uint8_t rec_len_tiva;
uint8_t recevied_tiva = 0;
uint8_t first_rec = 1;


void connect_tiva(void){
    // Enable the UART5 module.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
    // Wait for the UART5 module to be ready.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART5)){}
    // Initialize the UART
    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    UARTFIFODisable(UART5_BASE);

    // Initialize Pins of UART5 PE4 - PE5
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)){}
    GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    GPIOPinConfigure(GPIO_PE4_U5RX);
    GPIOPinConfigure(GPIO_PE5_U5TX);

    //UARTIntRegister(UART5_BASE, UART5_Handler_TIVA_Rec);
    //  UARTIntClear(UART5_BASE, UART_INT_RX);
    // IntEnable(INT_UART5);
    // UARTIntEnable(UART5_BASE, UART_INT_RX);
    //IntMasterEnable();
}

void rec_tiva_data(){
    if(first_rec == 0){
        uint8_t recieved = 0;
        while(UARTCharsAvail(UART5_BASE)){
            recieved = UARTCharGetNonBlocking(UART5_BASE);
            if(recieved == 13){   // The ASCII code for enter key is 13
                recevied_tiva = 1;
                break;
            }
            else{
                if(rec_len_tiva < BUFFER_SIZE_TIVA){
                    rec_buffer_tiva[rec_len_tiva] = recieved;
                    rec_len_tiva++;
                }
            }
        }
    }
    else{
        first_rec = 0;
    }
}

void send_tiva_char(unsigned char data){
    UARTCharPut(UART5_BASE, data);
    //UARTCharPutNonBlocking(UART5_BASE, data);
}


void stop_tiva(){
    //  UARTIntDisable(UART5_BASE, UART_INT_RX);
    UARTDisable(UART5_BASE);
}


void start_tiva(){
    //   UARTIntEnable(UART5_BASE, UART_INT_RX);
    UARTEnable(UART5_BASE);
}

/*
void UART5_Handler_TIVA_Rec(void){
    uint32_t stat = UARTIntStatus(UART5_BASE, true);
    UARTIntClear(UART5_BASE, stat);
    //UARTIntClear(UART5_BASE, UART_INT_RX);
    if(first_int == 0){
        unsigned char recieved = 0;
        recieved = UARTCharGet(UART5_BASE);
        if(recieved == 13){   // The ASCII code for enter key is 13
            recevied_tiva = 1;
        }
        else{
            if(rec_len_tiva < BUFFER_SIZE_TIVA){
                rec_buffer_tiva[rec_len_tiva] = recieved;
                rec_len_tiva++;
            }
        }
    }
    else{
        first_int = 0;
    }
}
 */
