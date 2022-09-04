#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define BUTTON1 32
#define BUTTON2 33

// Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup()
{
  // myStepper.setSpeed(18);
  Serial.begin(115200);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}

void loop()
{
  // Serial.println("clockwise");
  // myStepper.step(stepsPerRevolution);
  // delay(1000);
  if (digitalRead(BUTTON1) == LOW)
  {                            // Botão Pressionado;
    Serial.println("Clicou!"); // Liga led.
  }

  if (digitalRead(BUTTON2) == LOW)
  {                            // Botão Pressionado;
    Serial.println("Clicou!"); // Liga led.
  }
  // Serial.println("counterclockwise");
  // myStepper.step(-stepsPerRevolution);
  // delay(1000);
}