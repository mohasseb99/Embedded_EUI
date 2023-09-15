#include "HAL/PC.h"
#include "HAL/TIVA.h"
#include "HAL/buttons.h"
#include "HAL/leds.h"
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

extern uint8_t rec_buffer_pc[BUFFER_SIZE_PC];
extern uint8_t rec_len_pc;
extern uint8_t recevied_pc;
extern uint8_t pc_busy;

extern uint8_t rec_buffer_tiva[BUFFER_SIZE_TIVA];
extern uint8_t rec_len_tiva;
extern uint8_t recevied_tiva;

enum states{
    OFFLINE=0,
    LISTENER,
    ONLINE
};

uint8_t state = OFFLINE;

int main(void){
    initialize_leds();
    SW1_init();
    SW2_init();
    connect_pc();
    connect_tiva();

    uint8_t bts1, bts2;
    while(1){
        if(SW1_isPressed()){
            uint32_t bounce;
            for(bounce = 0; bounce < 3000; bounce++){}
            while(SW1_isPressed()){}
            bts1 = 1;
        }
        if(SW2_isPressed()){
            uint32_t bounce;
            for(bounce = 0; bounce < 3000; bounce++){}
            while(SW2_isPressed()){}
            bts2 = 1;
        }

        if(bts1 == 1){
            state = (state+1) % 3;
            bts1 = 0;
        }

        if(bts2 == 1){
            state = (state+2) % 3;   /* state + 3 - 1 as if we do state-1 it will be negativa and assigning it to unsigned */
            bts2 = 0;
        }

        switch(state){
        case OFFLINE:
            turn_on_Red();
            stop_pc();
            stop_tiva();
            break;
        case LISTENER:
            turn_on_Blue();
            stop_pc();
            start_tiva();
            rec_tiva_data();
            if(recevied_tiva){
                recevied_tiva = 0;
                uint8_t idx = 0;
                for(idx = 0; idx < rec_len_tiva; idx++){
                    send_pc_char(rec_buffer_tiva[idx]);
                }
                send_pc_char(13);
                send_pc_char('\n');
                rec_len_tiva = 0;
            }
            break;
        case ONLINE:
            turn_on_White();
            start_pc();
            start_tiva();
            rec_tiva_data();
            if((recevied_tiva) && (pc_busy == 0)){
                recevied_tiva = 0;
                uint8_t idx = 0;
                for(idx = 0; idx < rec_len_tiva; idx++){
                    send_pc_char(rec_buffer_tiva[idx]);
                }
                send_pc_char(13);
                send_pc_char('\n');
                rec_len_tiva = 0;
            }
            if(recevied_pc){
                recevied_pc = 0;
                uint8_t idx = 0;
                for(idx = 0; idx < rec_len_pc; idx++){
                    send_tiva_char(rec_buffer_pc[idx]);
                }
                rec_len_pc = 0;
            }
            break;
        default:
            break;
        }

    }
}
