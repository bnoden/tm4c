//#include <stdlib.h>
#include "lm4f120h5qr.h"


//const unsigned int MAX_COUNT = 12U;

const unsigned int BLINK = 300000U;

int volatile count;

int main() {
  
  SYSCTL_RCGCGPIO_R = 0x20U;     // enable clock for GPIOF
  GPIO_PORTF_DIR_R = 0x0eU;    //set pins 1, 2, 3 as outputs
  GPIO_PORTF_DEN_R = 0x0eU;
  
  while (1) {
    int i;
    
    for (i = 0x02; i < 0x0F; i+=0x02) {
      GPIO_PORTF_DATA_R = i;
      count = 0;
      while (count < BLINK/4) {++count;}
    }
    
    // int inc = 0x02;
    //GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R < 0x0c ? GPIO_PORTF_DATA_R+=inc : inc;
    //count = 0;
    //while (count < BLINK/4) {++count;}
  
  }
  
  
  
  
  return 0;
}