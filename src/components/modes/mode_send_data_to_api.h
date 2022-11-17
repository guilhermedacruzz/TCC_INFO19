#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include <Stepper.h>
#include "./mode_basic_sample.h"
#include "./utils/button_debounce.h"

class ModeSendDataToApi : public ModeBasicSample
{

private:
    const int stepsPerRevolution = 500;
    const int in1 = 13;
    const int in2 = 12;
    const int in3 = 14;
    const int in4 = 27;
    const int front = 25;
    const int back = 26;

    Stepper *stepper;
    ButtonDebounce *buttonFront;
    ButtonDebounce *sbuttonBack;

public:
    ModeSendDataToApi()
    {
        this->stepper = new Stepper(this->stepsPerRevolution, in1, in3, in2, in4);
        this->buttonFront = new ButtonDebounce(front);
        this->buttonFront = new ButtonDebounce(back);

        this->stepper->setSpeed(18);
    }

    void loop()
    {
        this->stepper->step(this->stepsPerRevolution);
    }
};

#endif