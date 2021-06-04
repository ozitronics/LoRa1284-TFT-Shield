/*****************************************************************************
  SimpleButtons.cpp - Arduino library to handle buttons on an analog pin

  May 28, 2021
  By Frank Crivelli, Ozitronics
******************************************************************************/

#include <SimpleButtons.h>

/*****************************************************************************
 Define structure that holds button data
 *****************************************************************************/
typedef struct
{
  uint16_t  adcThreshold; // aADC threshold value when button pressed
  uint8_t   code;         // button code returned
} TBUTTONDEF;

/*****************************************************************************
 Button data table
 Add/remove buttons as required
 *****************************************************************************/
TBUTTONDEF buttonTable[] =
{
  {  30, '1'},        // RIGHT
  { 160, '2'},        // UP
  { 350, '3'},        // DOWN
  { 530, '4'},        // LEFT
  { 770, '5'},        // SELECT
  {1025, NO_BUTTON}   // no button
};

/***************************************************************************** 
 Set return value for a button
 Calling parameters: button number, 
 Returns: button code
 *****************************************************************************/
void SimpleButtons::setButtonCode(uint8_t button_num, char c)
{
  if ((button_num >= 0) && (button_num < ARRAY_SIZE(buttonTable))) {
    buttonTable[button_num].code = c;
  }
}

/***************************************************************************** 
 Set ADC threshold value for a button
 Calling parameters : button number
                    : ADC threshold value (16-bit)
 Note: button numbers start at "0"
 *****************************************************************************/
void SimpleButtons::setADCThreshold(uint8_t button_num, uint16_t i)
{
  if ((button_num >= 0) && (button_num < ARRAY_SIZE(buttonTable))) {
    buttonTable[button_num].adcThreshold = i;
  }
}

/***************************************************************************** 
 Get button press and return button code
 Returns NO_BUTTON if no button pressed
 *****************************************************************************/
char SimpleButtons::getButton(void)
{
  char button = _buttonScan();    // scan keypad
  delay(20);                      // debounce
  if (_buttonScan() != button)    // scan again - if not same button
    return NO_BUTTON;           //  return "no button"
  
  switch (_lastButton) {
    case NO_BUTTON : // here if last button was "no button pressed"
                    _lastButton = button;             // save this button press
                    _lastButtonTime = millis();       // reset repeat time
                    _timeRepeat = _timeRepeatDelay;   // set repeat delay
                    break;

    default       : // here if last button was a "button press"
                    if (button == _lastButton) {      // if button IS SAME as last time...
                      if (millis() - _lastButtonTime < _timeRepeat)  // auto repeat?
                        button = NO_BUTTON;         // no, return "no button pressed"
                      else {
                        //if (_timeRepeatDelay == 0) button = NO_BUTTON;  // repeat disabled?
                        _lastButtonTime = millis();     // yes, reset repeat time
                        _timeRepeat = _timeRepeatRate;  // and repeat delay
                      }
                    }
                    else {                            // if button NOT SAME as last time
                      _lastButton = button;           // save new button
                      _lastButtonTime = millis();     // reset repeat time
                      _timeRepeat = _timeRepeatDelay; // set repeat delay
                    }
                    break;
  }
  return button;
}

/*****************************************************************************
 Read analog pin and return button code
 Returns NO_BUTTON if no button pressed
 *****************************************************************************/
uint8_t SimpleButtons::_buttonScan(void)
{
  char button = NO_BUTTON;            // default to "no button press"
  int input = analogRead(_buttonPin); // get analog value

  // work out what button it is
  for (int k = 0; k < ARRAY_SIZE(buttonTable); k++) {
    if (input < buttonTable[k].adcThreshold) {
      button = buttonTable[k].code;
      break;
    }
  }
  return button;
}  
