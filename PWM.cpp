
#include "PWM.h"
// initalize pin as output 

// set Fast PWM 10-bit mode, non-inverting
// Use Timer 3 


//initalize pin as output

// set Fast PWM 10-bit mode, inverting
// Use Timer 4 for 


void initPWM()
{
    //TIMER 3
    DDRE |= (1<<PORTE3);
    TCCR3A |= ( 1 << COM3A0);
    TCCR3A &=  ~(1 << COM3A0);
    TCCR3A |= (1 << WGM30) | (1 << WGM31);
    
    TCCR3B |= (1 << WGM32);
    TCCR3B &= ~(1 << WGM33);
    TCCR3B |= ( 1 << CS30);
    TCCR3B &= ~((1 <<CS31) | (1<<CS32));
    OCR3A = 0;
    //TIMER 4
    DDRH |= (1 << PORTH3);
    TCCR4A |= (1 << COM4A1);
    TCCR4A |= (1 << COM4A0);
    TCCR4A |= (1 << WGM40) | (1 << WGM41);
    TCCR4B |= (1 << WGM42);
    TCCR4B &= ~(1 << WGM43);
    TCCR4B |= (1 << CS40);
    TCCR4B &= ~((1 << CS41) | (1 << CS42));
OCR4A = 0 ;
}

//Set motor speed and direction with count registers using information obtained by ADC 
void SetMOTORspeed(int result) {
    if(result<512){
        OCR3A = 0x3FF - 2 * result;
        OCR4A = 0;
    }
    else if(result > 512){
        OCR3A = 0;
        OCR4A = 2 * result - 0x3FF;
    }
    else{
        OCR3A=0;
        OCR4A=0;
    }

}
