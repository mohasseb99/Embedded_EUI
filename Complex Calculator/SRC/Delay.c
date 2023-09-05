#include "../INC/Delay.h"

void Delay(unsigned short delay){
    NVIC_ST_RELOAD_R = delay * Freq_Factor; /* Load SYSTick timer value */
    NVIC_ST_CTRL_R = 0b1; /* Start Counter */
    while(!(NVIC_ST_CTRL_R & (1<<16))); /* Wait for timer to reach 0 */
    NVIC_ST_CURRENT_R = 0; /* Clears count flag in control register */
    NVIC_ST_CTRL_R &= 0; /* Stop timer */
}

void Delay_Micro(unsigned long delay){
    NVIC_ST_RELOAD_R = delay * Freq_Factor_Micro; /* Load SYSTick timer value */
    NVIC_ST_CTRL_R = 0b1; /* Start Counter */
    while(!(NVIC_ST_CTRL_R & (1<<16))); /* Wait for timer to reach 0 */
    NVIC_ST_CURRENT_R = 0; /* Clears count flag in control register */
    NVIC_ST_CTRL_R &= 0; /* Stop timer */
}
