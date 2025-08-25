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
        void enableAll();
    private:
        int _dataPin;
        int _clockPin;
        int _latchPin;
        int _numberOfTubes;
        String _text;
        byte VfdTable;
};


#endif