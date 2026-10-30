#include <Arduino.h>
#include <TM1637Display.h>

// define the CLK and DIO
#define CLK 2
#define DIO 3

unsigned int angka = 0;
TM1637Display display(CLK, DIO);
int merah = 4;
int kuning = 5;
int hijau = 6;

uint8_t allDigits[] = {0xff, 0xff, 0xff, 0xff};
uint8_t blank[] ={0x0, 0x0, 0x0, 0x0};

void setup() {
 display.setBrightness(0x0f);
 pinMode(merah, OUTPUT);
 pinMode(kuning, OUTPUT);
 pinMode(hijau, OUTPUT);
}

void loop() {
  for (angka = 30; angka>0; angka--){
  display.showNumberDec(angka);
  delay(1000);
  if (angka > 20){
    digitalWrite(merah, HIGH);
    digitalWrite(kuning, LOW);
  } else {
    digitalWrite(merah, LOW);
  }

  if (angka <= 20){
    digitalWrite(hijau, HIGH);
  } else {
    digitalWrite(hijau, LOW);
  }

  if (angka <= 5){
    digitalWrite(kuning, HIGH);
    digitalWrite(hijau, LOW);
  } else {
    digitalWrite(kuning, LOW);
  }
  }

  




}
