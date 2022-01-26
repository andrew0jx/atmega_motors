

#include "timer.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer1(){
    TCCR1B |= (1<<CS11);
    TCCR1B &= ~(1<<CS12) | (1 << CS10);
    TCCR1A &= ~(1 << WGM10);
    TCCR1A &= ~(1 << WGM11);
    TCCR1B |= (1 << WGM12);
    TCCR1B &= ~(1 << WGM13);
    OCR1A = 2;
}

/* This delays the program an amount of microseconds specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
    unsigned int cnt = 0;
    TCNT1 = 0;
    while (cnt < delay){
        if (TIFR1 & (1 << OCF1A)){
            cnt++;
            TIFR1 |= (1 << OCF1A);
        }
    }
}