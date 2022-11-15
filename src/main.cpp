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

NVS nvs;

ModeBasicSample *mode;

void setup()
{
    Serial.begin(115200);
    
    mode = new ModeConfiguration();
}

void loop()
{
    mode->loop();
}