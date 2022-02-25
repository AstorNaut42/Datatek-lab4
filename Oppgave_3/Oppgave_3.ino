#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;
Zumo32U4LineSensors linesensor;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

int maxSpeed = 400;
int positions;
int linesensorValues;

Zumo32U4LCD display;


void setup() {


  linesensor.initFiveSensors();

  buttonA.waitForButton();

  delay(1000);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setSpeeds(speed, speed);
    linesensor.calibrate();
    delay(1);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setSpeeds(speed, speed);
    linesensor.calibrate();
    delay(1);
  }
}





void loop() {

  positions = linesensor.readLine(linesensorValues);


  display.clear();
  display.gotoXY(0, 1);
  display.print(F("Hei"));

  delay(300);


}
