//#include <stdlib.h>
#include "lm4f120h5qr.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

void delay(int iter);

const unsigned int BLINK = 300000U;

int main() {
  
  SYSCTL_RCGCGPIO_R |= (1U << 5);     // enable clock for GPIOF
  SYSCTL_GPIOHBCTL_R |= (1U << 5);
  GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
  while(1) {
  
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    
    delay(BLINK*2);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    
    delay(BLINK);
    
  }
  
  return 0;
}

void delay(int iter) {
    int volatile count = 0;
    while (count < BLINK) {     // delay loop
      ++count;
    }
}