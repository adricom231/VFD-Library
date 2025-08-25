#include <Arduino.h>

int latchPin_vfd = 2;
int clockPin_vfd = 1;
int dataPin_vfd = 44;

int latchPin_enable = 7;
int clockPin_enable = 8;
int dataPin_enable = 9;


byte VfdTable[128] = {0};
void tableSetup(){
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

void printDisplay(String input){
  digitalWrite(latchPin_vfd, LOW);
  char SelInput = ' ';
  if(input.length() == 5){    input = input + " ";  }
  if(input.length() == 4){    input = " " + input + " ";  }
  if(input.length() == 3){    input = " " + input + "  ";  }
  if(input.length() == 2){    input = "  " + input + "  ";  }
  if(input.length() == 1){    input = "  " + input + "   ";  }
  for(int i = 6; i >= 0 ; i--){
    SelInput = input[i];
    shiftOut(dataPin_vfd, clockPin_vfd, MSBFIRST, VfdTable[SelInput]);
  }
  digitalWrite(latchPin_vfd, HIGH);
}


void enableAll(){
  byte data =B11111111;
  digitalWrite(latchPin_enable, LOW);
  shiftOut(dataPin_enable, clockPin_enable, MSBFIRST, data);
  digitalWrite(latchPin_enable, HIGH);
}



void setup() {
  pinMode(latchPin_vfd, OUTPUT);
  pinMode(clockPin_vfd, OUTPUT);
  pinMode(dataPin_vfd, OUTPUT);
  pinMode(latchPin_enable, OUTPUT);
  pinMode(clockPin_enable, OUTPUT);
  pinMode(dataPin_enable, OUTPUT);
  
  
  tableSetup();
  enableAll();
  printDisplay("-[A5]-");


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
