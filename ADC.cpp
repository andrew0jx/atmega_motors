
#include "ADC.h"

  // set voltage references to be AVCC
  //(RIGHT JUSTIFIED)
  // set Auto Trigger Source Selection
  // set to free-running mode 
  // enable auto-triggering and turn-on ADC
  // set the pre-scaler
  // disable ADC0 pin digital input
  // start the first conversion
  
void initADC()
{
  //Ref 5V Output
  ADMUX |= (1<<REFS0);
  ADMUX &= ~(1 << REFS1);
  //right justify
  ADMUX &= ~(1<<ADLAR);
//Specifcy input channel and mode
  ADMUX &= ~((1<<MUX4)| (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));

  ADCSRB &= ~(1 << MUX5);
  ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0)); //Auto trigger and free running mode
  ADCSRA|= (1 << ADEN) | (1 << ADATE); // enable and turn on
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //prescalar
  DIDR0 |= (1 << ADC0D); // disable ADC0 pin

  ADCSRA |= ( 1 << ADSC); //start first conversion
}

