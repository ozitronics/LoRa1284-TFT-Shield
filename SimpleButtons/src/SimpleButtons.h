#pragma once
/*****************************************************************************
  SimpleButtons.h - Arduino library to handle buttons on an analog pin

  Memory Usage: Flash = depends on board definition and compile settings
                RAM   = 22 bytes
  
  May 28, 2021
  By Frank Crivelli, Ozitronics
******************************************************************************/

#include <Arduino.h>

// Miscellaneous defines
const uint8_t NO_BUTTON = 0;
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

// SimpleButtons class to one analog input button stream
class SimpleButtons
{
public:
  SimpleButtons(uint8_t buttonPin) :
      _buttonPin(buttonPin),
      _lastButton(NO_BUTTON),
      _lastButtonTime(0),
      _timeRepeat(0),
      _timeRepeatDelay(500),
      _timeRepeatRate(100)
  {}
  
  ~SimpleButtons(void) {};

  // Data handling
  void        setButtonCode(uint8_t keynum, char c);        // set return value for button
  void        setADCThreshold(uint8_t keynum, uint16_t i);  // set ADC threshold for button
  inline void setRepeatDelayTime(uint16_t t)  { _timeRepeatDelay = t; };  // set repeat delay time
  inline void setRepeatRateTime(uint16_t t)   { _timeRepeatRate = t; };   // set repeat rate
  char        getButton(void);    // read value and return button pressed
                                  // NO_BUTTON if no button pressed

private:
  uint8_t     _buttonScan();      // read analog pin and return ADC code

protected:
  uint8_t     _buttonPin;         // analog input port
  uint32_t    _lastButtonTime;    // last time a button was returned
  char        _lastButton;        // last button value read
  uint16_t    _timeRepeatDelay;   // time before first repeat
  uint16_t    _timeRepeatRate;    // time for repeats after first repeat
  uint16_t    _timeRepeat;        // time for auto-repeat
  uint8_t     _buttonFlag = 0;    // last known button state
                                  // 0 = no button pressed, look for a button press
                                  // 1 = a button is pressed, look for button release
};
