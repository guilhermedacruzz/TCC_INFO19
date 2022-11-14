#include <Arduino.h>
#include <Stepper.h>
#include "utils/button_debounce.h"
#include "utils/nvs.h"
#include "models/settings.h"
#include "components/modes/mode_basic_sample.h"
#include "components/modes/mode_configuration.h"

const int stepsPerRevolution = 500;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define BUTTON1 32
#define BUTTON2 33

#define FRENTE 25
#define TRAS 26

// Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// ButtonDebounce frente(FRENTE);
// ButtonDebounce tras(TRAS);

// int sentido = 1;

// void action() {
//   sentido *= -1;
//   Serial.println(sentido);
// }

NVS nvs;

ModeBasicSample *mode;

void setup()
{
    // myStepper.setSpeed(60);
    Serial.begin(115200);

    mode = new ModeConfiguration();
}

void loop()
{
    mode->loop();
    // frente.read(action);
    // tras.read(action);

    // myStepper.step(8 * sentido);
}