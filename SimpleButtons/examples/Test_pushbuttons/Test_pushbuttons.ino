// Read ADC value as each button is pressed and print to serial monitor
//
#define ADCpin A0

void setup()
{
  Serial.begin(9600);
  pinMode(ADCpin, INPUT);
  Serial.println("Press a button...");
}

void loop()
{
  int ADCvalue;

  ADCvalue = analogRead(ADCpin);        // read the value from the port
  if (ADCvalue < 1023) {
    Serial.println(ADCvalue);
  }
  while (analogRead(ADCpin) != 1023);   // wait for button release
  delay(100);
}

