#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include <Stepper.h>
#include "./mode_basic_sample.h"
#include "./components/widgets/button_debounce.h"
#include "./models/motor.h"
#include "./utils/enums/motor_status.h"
#include "./utils/enums/gate_status.h"

const int stepsPerRevolution = 500;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

#define BUTTON_FRONT 25
#define BUTTON_BACK 26
#define BUTTON_CONTROL 33

class ModeSendDataToApi : public ModeBasicSample
{

private:
    Stepper stepper = Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
    ButtonDebounce
        buttonFront = ButtonDebounce(BUTTON_FRONT),
        buttonBack = ButtonDebounce(BUTTON_BACK),
        buttonControl = ButtonDebounce(BUTTON_CONTROL);
    Motor motor;

    void start()
    {
        GateStatus gateStatus = RUNNIG;
        MotorStatus motorStatus = STOPED;

        if (!this->buttonFront.read())
        {
            gateStatus = CLOSED;
        }
        else if (!this->buttonBack.read())
        {
            gateStatus = OPENED;
        }

        this->motor = Motor(motorStatus, gateStatus);
    }

public:
    ModeSendDataToApi()
    {
        this->stepper.setSpeed(18);

        this->start();

        this->buttonControl.setAction([]{
            Serial.println("press");
        });
    }

    void loop()
    {
        //this->stepper.step(3);
        this->buttonControl.execute();
    }
};

#endif