#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include <Stepper.h>
#include "./mode_basic_sample.h"
#include "./components/widgets/button_debounce.h"

const int stepsPerRevolution = 500;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define FRONT 25
#define BACK 26

class ModeSendDataToApi : public ModeBasicSample
{

private:
    Stepper *stepper;
    ButtonDebounce *buttonFront, *buttonBack;

public:
    ModeSendDataToApi()
    {
        this->stepper = new Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
        this->buttonFront = new ButtonDebounce(FRONT);
        this->buttonBack = new ButtonDebounce(BACK);

        this->stepper->setSpeed(18);
    }

    void loop()
    {
        this->stepper->step(stepsPerRevolution);
    }
};

#endif