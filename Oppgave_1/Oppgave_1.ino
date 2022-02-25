#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

void setup(){
  buttonA.waitForButton();

  delay(1000);
  }


void loop(){
  ledRed(1);
  ledYellow(1);
  ledGreen(1);

  delay(500);

  ledRed(0);
  ledYellow(0);
  ledGreen(0);

  delay(500);
  
  }
