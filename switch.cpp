// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

//Setup pin D0 as input 
//Set pull up resistance 
//Setup external interupt with any edge change 

void initSwitchPD0()
{
PORTD |= (1 << PORTD0);
DDRD &= ~(1 << PORTD0);
PCICR |= (1 << PCIE0);
PCMSK0 |= (1 << INT0);
}