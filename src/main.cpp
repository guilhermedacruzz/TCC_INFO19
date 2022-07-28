#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  myStepper.setSpeed(5);
  Serial.begin(115200);
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}