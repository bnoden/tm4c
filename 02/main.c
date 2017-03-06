//#include <stdlib.h>

#define RCGCGPIO (*((unsigned int *)0x400FE608U))        // Clock Gating Control
#define GPIOF_BASE 0x40025000U
#define GPIO_DIR (*((unsigned int*)(GPIOF_BASE+0x400U)))
#define GPIO_DEN (*((unsigned int*)(GPIOF_BASE+0x51CU))) // Digital ENable
#define GPIO_DATA (*((unsigned int*)(GPIOF_BASE+0x3FCU)))


//const unsigned int MAX_COUNT = 12U;

const unsigned int BLINK = 300000U;

int count;

int main() {
  
  RCGCGPIO = 0x20U;
  GPIOF_DIR = 0x0eU;
  GPIOF_DEN = 0x0eU;
  
  while (1) {
  
    GPIO_DATA = 0x0a;
    count = 0;
    while (count < BLINK) {++count;}
    
    *((unsigned int*)0x400253fcU) = 0x04;
    count=0;
    while (count < BLINK) {++count;}
  
  }
  
  
  
  
  return 0;
}

// void blinkAll() {
  //int colors = 0x02;
  //while (colors) {
    //colors = colors < 0x0F ? ++colors : 0x02;
    //*((unsigned int*)0x400253fcU) = colors;
  //}
//}