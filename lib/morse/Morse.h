#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse
{
  public:
    Morse();
    virtual ~Morse();
    char getLettre(int);
  private:
  // Calibration values
  char lettreTraduite;
};

#endif