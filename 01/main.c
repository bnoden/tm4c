#include <stdlib.h>

//const unsigned int MAX_COUNT = 12U;

//void blinkAll(void);

const unsigned int BLINK = 300000U;

int count;

int main() {
  
  *((unsigned int*)0x400fe608U) = 0x20U;
  *((unsigned int*)0x40025400U) = 0x0eU;
  *((unsigned int*)0x4002551cU) = 0x0eU;
  
  while (1) {
  
    //blinkAll();
    *((unsigned int*)0x400253fcU) = 0x0a;
    count = 0;
    while (count < BLINK) {++count;}
    
    //blinkAll();
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