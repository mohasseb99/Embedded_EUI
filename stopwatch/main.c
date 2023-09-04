#include "INC/DIO.h"
#include "INC/systick.h"
#include "INC/LCD.h"
#include "INC/EXIT.h"
#include "INC/stop_watch.h"
#include "INC/tm4c123gh6pm.h"
#include "INC/bitwise_operation.h"

void SYSTICK_Handler(void);
int main(void);
void SYSTICK_Handler(void);
void GPIOF_Handler(void);

unsigned char start = 1;
extern unsigned long min, sec;
extern unsigned long min_lap, sec_lap;

int main(void)
{
    DIO_Init(PORTF, PIN0, IN);
    DIO_Init(PORTF, PIN4, IN);
    LCD_INIT();
    INT_PIN_INIT(PORTF, PIN0, EDGE_MODE, FALLING_EDGE);
    INT_PIN_INIT(PORTF, PIN4, EDGE_MODE, FALLING_EDGE);

    write_string("   Stop Watch   Mohasseb   Monem");
    unsigned long i = 0;
    for(i = 0; i < 1000000; i++){}
    SYSTICK_INT_INIT_ms(1000);
    while(1){
        print_time();
    }
    return 0;
}

void SYSTICK_Handler(void){
    SYSTICK_clear();
    sec++;
}

void GPIOF_Handler(void){
    unsigned long i;
    for(i = 0; i < 300000; i++){}
    if(INT_PIN_CHECK(PORTF, PIN0)){
        start ^= 1;
        toggle_enable();      // if systick is enabled --> disable it, if disabled --> enable it
        INT_PIN_CLEAR(PORTF, PIN0);
    }
    else if(INT_PIN_CHECK(PORTF, PIN4)){
        if(start==0){
            min = 0;
            sec = 0;
            min_lap = 0;
            sec_lap = 0;
            toggle_enable();    // if systick is enabled --> disable it, if disabled --> enable it
            INT_PIN_CLEAR(PORTF, PIN4);
            start = 1;
        }
        else if(start == 1){
            min_lap = min;
            sec_lap = sec;
            INT_PIN_CLEAR(PORTF, PIN4);
        }
    }
}
