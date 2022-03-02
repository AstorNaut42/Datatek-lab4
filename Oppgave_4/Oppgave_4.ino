#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;
Zumo32U4LineSensors linesensor;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

int maxSpeed = 400;
int positions;

#define NUM_SENSORS 5
unsigned int lineSensorValues[NUM_SENSORS];

Zumo32U4LCD display;


void setup() {

  Serial.begin(9600);


  linesensor.initFiveSensors();

  buttonA.waitForButton();

  calibrate();

  delay(1000);


}


void calibrate() {

  for (int i = 0; i < 150; i++) {

    linesensor.calibrate();

    if (i < 50) {
      motors.setSpeeds(200, -200);
    }

    if (i > 50 && i < 100) {
      motors.setSpeeds(0, 0);
    }

    if (i > 100) {
      motors.setSpeeds(-200, 200);
    }
  }
  motors.setSpeeds(0, 0);


}




void loop() {


  positions = linesensor.readLine(lineSensorValues);
  int lastPos = positions;
  int posDiff = abs( positions - lastPos );

  Serial.println(posDiff);

  int speeds = map(posDiff, 0, 2000, 0, 400);

  if (positions > 1950 && positions < 2050){
    motors.setSpeeds(200, 200);
    } 

  // Hvis bilen er til høyre for teipen
  if (positions < 1950) {
    motors.setSpeeds(300, 50);

  }
  // Hvis bilen er til venstre for teipen
  if (positions > 2050) {
    motors.setSpeeds(50, 300);
  }
  else{
    motors.setSpeeds(50, 50);
    }


  display.clear();
  display.gotoXY(0, 1);
  display.print(positions);

}
