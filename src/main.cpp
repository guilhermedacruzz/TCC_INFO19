#include <Arduino.h>
#include <Stepper.h>
#include "button_debounce.h"

const int stepsPerRevolution = 2048;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define BUTTON1 32
#define BUTTON2 33

#define FRENTE 25
#define TRAS 26

// Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

ButtonDebounce button1(BUTTON1);
ButtonDebounce button2(BUTTON2);
ButtonDebounce frente(FRENTE);
ButtonDebounce tras(TRAS);

void setup()
{
  // myStepper.setSpeed(18);
  Serial.begin(115200);
  delay(1000);
}

void loop()
{
  button1.read();
  button2.read();
  frente.read();
  tras.read();
  
  // Serial.println("clockwise");
  // myStepper.step(stepsPerRevolution);
  // delay(1000);
  
  // Serial.println("counterclockwise");
  // myStepper.step(-stepsPerRevolution);
  // delay(1000);
}