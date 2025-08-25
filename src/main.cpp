#include <Arduino.h>



byte VfdTable[128] = {0};
void setup() {
  VfdTable['-'] = B00001000;
  VfdTable['['] = B00010111;
  VfdTable[']'] = B10110001;
  VfdTable['0'] = B10110111;
  VfdTable['1'] = B10100000;
  VfdTable['2'] = B00111011;
  VfdTable['3'] = B10111001;
  VfdTable['4'] = B10101100;
  VfdTable['5'] = B10011101;
  VfdTable['6'] = B10011111;
  VfdTable['7'] = B10110000;
  VfdTable['8'] = B10111111;
  VfdTable['9'] = B10111101;
  VfdTable['A'] = B10111110;
  VfdTable['B'] = B10111111;
  VfdTable['C'] = B00010111;
  VfdTable['D'] = B10110111;
  VfdTable['E'] = B00011111;
  VfdTable['F'] = B00011110;

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
