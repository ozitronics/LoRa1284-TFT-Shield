// Example program for SimpleButtons library
// Using buttons on LoRa1284 TFT Shield shield
//
// Print the button pressed to the serial monitor
//
#include <SimpleButtons.h>

#define ADCpin A7
SimpleButtons TFTbuttons(ADCpin);    // define analog port for buttons

void setup()
{
  Serial.begin(9600);

  // adjust ADC thresholds for LoRa1284 TFT Shield
  TFTbuttons.setADCThreshold(0, 20);
  TFTbuttons.setADCThreshold(1, 530);
  TFTbuttons.setADCThreshold(2, 700);

  Serial.println("Press a button...");
}

void loop()
{
  char	c = TFTbuttons.getButton();
  if (c != NO_BUTTON) {
    Serial.print("Button = ");
    Serial.println(c);
  }
}
