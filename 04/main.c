//#include <stdlib.h>
#include "lm4f120h5qr.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

const unsigned int BLINK = 300000U;

int volatile count;

int main() {
  
  SYSCTL_RCGCGPIO_R |= (1U << 5);     // enable clock for GPIOF
  GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  GPIO_PORTF_DATA_R |= LED_BLUE;
  while(1) {
  
    GPIO_PORTF_DATA_R |= LED_RED;
    
    count = 0;
    while (count < BLINK) {     // delay loop
      ++count;
    }
    
    GPIO_PORTF_DATA_R &= ~LED_RED;
    count = 0;
    while (count < BLINK) {      // delay loop
      ++count;
    }
    
  }
  
  
  
  return 0;
}