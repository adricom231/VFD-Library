#include <Arduino.h>
#include <VFD.h>


VFD::VFD(int dataPin, int clockPin, int latchPin, int numberOfTubes)
{
    _dataPin = dataPin;
    _clockPin = clockPin;
    _latchPin = latchPin;
    _numberOfTubes = numberOfTubes;
    byte VfdTable[128] = {0};
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

void VFD::begin()
{
    pinMode(_dataPin, OUTPUT);
    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);

}

void VFD::printDisplay(String text){
    digitalWrite(_latchPin, LOW);
    char SelInput = ' ';
    if(text.length() < _numberOfTubes){
        int NChar = _numberOfTubes - text.length();
        if((NChar % 2) == 1){
            NChar = NChar -1;
            text = text + ' ';}
        NChar = NChar / 2;
        for(int i = 0 ; i < NChar ; i++){ text = text + ' '; }
        for(int i = 0 ; i < NChar ; i++){ text = ' ' + text; }     
  }
  for(int i = _numberOfTubes; i >= 0 ; i--){
    SelInput = text[i];
    shiftOut(_dataPin, _clockPin, MSBFIRST, VfdTable[SelInput]);
  }
  digitalWrite(_latchPin, HIGH);
}