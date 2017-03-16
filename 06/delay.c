void delay(int);

void delay(int iter) {
  int volatile count = 0;
    while (count < iter) {     // delay loop
      ++count;
    }
}