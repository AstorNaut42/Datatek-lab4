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


}


void calibrate() {

  for (int i = 0; i < 150; i++) {

    linesensor.calibrate();

    if (i < 50) {
      motors.setSpeeds(200, 200);
    }

    if (i > 50 && i < 100) {
      motors.setSpeeds(0, 0);
    }

    if (i > 100) {
      motors.setSpeeds(-200, -200);
    }
  }
  motors.setSpeeds(0, 0);


}


void loop() {

  positions = linesensor.readLine(linesensorValues);

  calibrate();


  display.clear();
  display.gotoXY(0, 1);
  display.print(positions);

  delay(5000);


}
