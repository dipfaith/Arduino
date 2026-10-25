#include <Arduino.h>
#include <TM1637Display.h>

// define the CLK and DIO
#define CLK 2
#define DIO 3

// define the traffic lights
unsigned int i = 0;
int red = 5;
int yellow = 4;
int green = 6;

TM1637Display display(CLK, DIO);
// define the time
#define TEST_DELAY 1000
uint8_t allDigits[] = {0xff, 0xff, 0xff, 0xff};
uint8_t blank[] ={0x0, 0x0, 0x0, 0x0};

void setup() {
display.setBrightness(0x0f);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(4, OUTPUT);
}

void loop() {

for(int i=20; i>5; i--){
 display.showNumberDec(i);
 if (i <= 6){
  digitalWrite(red, HIGH);
  } else {
    digitalWrite(red, LOW);
  }
}

delay(TEST_DELAY);

for(int i=20; i>0; i--){
 display.showNumberDec(i);
 if (i <= 10){
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  } else {
    digitalWrite(yellow, LOW);
  }
}

delay(TEST_DELAY);

for(int i=20; i>4; i--){
 display.showNumberDec(i);
 if (i<= 15){
  digitalWrite(green, HIGH);
  } else {
    digitalWrite(green, LOW);
  }
}

delay(TEST_DELAY);

for(int i=20; i>0; i--){
 display.showNumberDec(i);
 if (i = 10){
  digitalWrite(yellow, HIGH);
  } else {
    digitalWrite(yellow, LOW);
  }
}

delay(TEST_DELAY);
}

