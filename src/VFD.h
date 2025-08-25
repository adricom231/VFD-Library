/*
    Simple Driver Library for IV-3 VFD Clock By Adricom
    Created by Adricom 25.08.2025
    Released on GitHub
*/


#ifndef VFD_h
#define VFD_h

#include <Arduino.h>

class VFD
{
    public:
        VFD(int dataPin, int clockPin, int latchPin, int numberOfTubes);
        void begin();
        void printDisplay(String text);
        void onAll();
    private:
        int _dataPin;
        int _clockPin;
        int _latchPin;
        int _numberOfTubes;
        String _text;
        char SelInput;
        byte _data;
        byte _VfdTable[128];
};


#endif