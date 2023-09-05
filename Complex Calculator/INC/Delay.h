
#ifndef MCAL_DELAY_H_

#include "tm4c123gh6pm.h"

#define MCAL_DELAY_H_

#define Freq_Factor 4000 /* Change according to clock frequency */
#define Freq_Factor_Micro 4 /* Change according to clock frequency */

void Delay(unsigned short delay);
void Delay_Micro(unsigned long delay);

#endif /* MCAL_DELAY_H_ */
