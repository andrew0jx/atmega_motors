
#include <avr/io.h>
#include "ADC.h"
#include "timer.h"
#include "PWM.h"
#include <Arduino.h> // only for debugging.  Not on final submission
#include "switch.h"

//Create statemachine for button debouncing
//When system is on motor will rotate based on potentiometer location 
//System turns off when button is pushed
// Create states.
typedef enum stateType_enum {
  wait_press, debounce_press, wait_release, debounce_release
} stateType;

// Initialize states.
volatile stateType state = wait_press;

int main()
{
   
    initTimer0();
    initADC();
    initPWM();
    initSwitchPD0();
    Serial.begin(9600);
    sei();
    unsigned int result = 0;
    float voltage = 0;
    while(1)
    {

    result = ADCL;
    result += ((unsigned int) ADCH)<<8;
    voltage = result * (4.72/1024.0);
    Serial.println(voltage);
      SetMOTORspeed(result);
      switch(state){
      case wait_press:
        break;

      case debounce_press:
        delayMs(1);

        state = wait_release;

        break;

      case wait_release:
        break;

      case debounce_release:
        delayMs(1);

        state = wait_press;

        break;
    }
    }

    return 0;
}
// Establish ISR using external interput on PORTD
  ISR(INT0_vect){
  if( state == wait_press) {
      state = debounce_press;
  }
  else if (state == wait_release) {
    state = debounce_release;
 }  
} 
