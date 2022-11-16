#include <Arduino.h>
#include <Stepper.h>
#include "utils/button_debounce.h"
#include "utils/non_volatile_storage.h"
#include "models/settings.h"
#include "components/modes/mode_basic_sample.h"
#include "components/modes/mode_configuration.h"
#include "components/modes/mode_create_yourself_in_database.h"
#include "utils/custom_wifi.h"

const int stepsPerRevolution = 500;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define BUTTON1 32
#define BUTTON2 33

#define FRENTE 25
#define TRAS 26

ModeBasicSample *mode;

void setup()
{
    Serial.begin(115200);

    NonVolatileStorage nonVolatileStorage;
    JsonTools jsonTools;

    if (!nonVolatileStorage.check("name"))
    {
        mode = new ModeConfiguration(&nonVolatileStorage, &jsonTools);
    }
    else
    {
        if(!nonVolatileStorage.check("id")) {
            mode = new ModeCreateYourselfInDatabase(&nonVolatileStorage, &jsonTools);
        }
    }
}

void loop()
{
    mode->loop();
}