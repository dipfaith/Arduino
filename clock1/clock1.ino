#include <Arduino.h>
#include <TM1637Display.h>

// define the CLK and DIO
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);
// define the time
#define TEST_DELAY 15000
uint8_t allDigits[] = {0xff, 0xff, 0xff, 0xff};
uint8_t blank[] ={0x0, 0x0, 0x0, 0x0};

void setup() {
  
  display.setBrightness(0x0f);
}

void loop() {
 /* display.setSegments(blank);
  display.showNumberDec(125, false, 3,1);
  delay(TEST_DELAY);
  */
  for(int i=0; i<=20; i++){
    display.showNumberDec(i);
     delay(1000);
  }

 

/* for(int i=20; i>= 0; i--){
    display.showNumberDec(i);
  }
  delay(2000);
     
  display.setSegments(blank);
  display.showNumberDec(384, true);
  delay(TEST_DELAY);
  
  display.setSegments(blank);
  display.showNumberDec(6769, true);
  delay(1000);
     */
}
