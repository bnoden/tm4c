//#include <stdlib.h>

#define RCGCGPIO (*((unsigned int *)0x400FE608U))        // Clock Gating Control
#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR (*((unsigned int*)(GPIOF_BASE+0x400U)))
#define GPIOF_DEN (*((unsigned int*)(GPIOF_BASE+0x51CU))) // Digital ENable
#define GPIOF_DATA (*((unsigned int*)(GPIOF_BASE+0x3FCU)))


//const unsigned int MAX_COUNT = 12U;

const unsigned int BLINK = 300000U;

int volatile count;

int main() {
  
  RCGCGPIO = 0x20U;
  GPIOF_DIR = 0x0eU;
  GPIOF_DEN = 0x0eU;
  
  while (1) {
    int i;
    
    for (i = 0x02; i < 0x0F; i++) {
      GPIOF_DATA = GPIOF_DATA < 0x0F ? i : 0x02;
      count = 0;
      while (count < BLINK/10) {++count;}
    }
  
  }
  
  
  
  
  return 0;
}