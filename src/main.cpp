#include <Arduino.h>
#include <VFD.h>
int latchPin_vfd = 2;
int clockPin_vfd = 1;
int dataPin_vfd = 44;

int latchPin_enable = 7;
int clockPin_enable = 8;
int dataPin_enable = 9;
const int NrOfTubes = 6;

VFD vfd(dataPin_vfd, clockPin_vfd, latchPin_vfd, NrOfTubes);


void enableAll(){
  byte data =B11111111;
  digitalWrite(latchPin_enable, LOW);
  shiftOut(dataPin_enable, clockPin_enable, MSBFIRST, data);
  digitalWrite(latchPin_enable, HIGH);
}



void setup() {
  pinMode(latchPin_enable, OUTPUT);
  pinMode(clockPin_enable, OUTPUT);
  pinMode(dataPin_enable, OUTPUT);  
  vfd.begin();
  enableAll();
  vfd.printDisplay("[AS]");

}


void loop() {

}




//1- right bottom
//2- przecinek
//- 3right top
//4- top
//5- middle
//6- left top
//7- left bottom
//8- bottom
//byte data =B11111111;
//byte data_z = B00000000;
//byte data_0 =B10110111; 
//byte data_9 =B10111101; 
//byte data_8 =B10111111;
//byte data_7 =B10110000;
//byte data_6 =B10011111;
//byte data_5 =B10011101;
//byte data_4 =B10101100;
//byte data_3 =B10111001;
//byte data_2 =B00111011;
//byte data_1 =B10100000;
