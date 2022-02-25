#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

void setup(){
  buttonA.waitForButton();

  delay(1000);
  }


void loop(){


   
  ledYellow(1);
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }
  
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

    for (int speed = 0; speed <= 400; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  delay(500);

  for (int speed = 0; speed <= 400; speed++)
    {
    motors.setRightSpeed(speed);
    motors.setLeftSpeed(speed/2);
    delay(2); 
    }
  delay(400);

  for (int speed = 400; speed >= 0; speed--){
    motors.setRightSpeed(speed);
    motors.setLeftSpeed(speed/2);
    delay(2);
    }


    
  for (int speed = 0; speed <= 400; speed++)
    {
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed/2);
    delay(2); 
    }
  delay(400);

  for (int speed = 400; speed >= 0; speed--){
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed/2);
    delay(2);
    }
  
  
}
