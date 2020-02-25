#include <Arduino.h>

#define redAnode A0
#define greenAnode A1
#define blueAnode A2

#define redCatode A3
#define greenCatode A4
#define blueCatode A5

void setup()
{
}

void resetLeds()
{
  delay(1000);
  analogWrite(redCatode, 0);
  analogWrite(redAnode, 255);
  analogWrite(greenCatode, 0);
  analogWrite(greenAnode, 255);
  analogWrite(blueCatode, 0);
  analogWrite(blueAnode, 255);
}

void loop()
{
  analogWrite(redCatode, 255);
  analogWrite(redAnode, 0);
  resetLeds();
  analogWrite(greenCatode, 255);
  analogWrite(greenAnode, 0);
  resetLeds();
  analogWrite(blueCatode, 255);
  analogWrite(blueAnode, 0);
  resetLeds();
}