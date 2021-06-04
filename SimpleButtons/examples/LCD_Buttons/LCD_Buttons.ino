// Example program for SimpleButtons library
// Using buttons on LCD shield
//
// Print the button pressed to the serial monitor
//
#include <SimpleButtons.h>
SimpleButtons lcdKeypad(A7);    // define analog port for buttons

void setup()
{
  Serial.begin(9600);

  // adjust ADC thresholds for LoRa1284 TFT Shield
  lcdKeypad.setADCThreshold(0, 20);
  lcdKeypad.setADCThreshold(1, 530);
  lcdKeypad.setADCThreshold(2, 700);

  Serial.println("Press a button...");
}

void loop()
{
  char	c = lcdKeypad.getButton();
  if (c != NO_BUTTON) {
    Serial.print("Button = ");
    Serial.println(c);
  }
}
