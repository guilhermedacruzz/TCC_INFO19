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

class ModeSendDataToApi : public ModeBasicSample
{

private:
    Stepper *stepper;
    ButtonDebounce *buttonFront, *buttonBack;
    Motor motor;

    void start() {
        GateStatus gateStatus = RUNNIG;
        MotorStatus motorStatus = STOPED;

        if(!this->buttonFront->read()) {
            gateStatus = CLOSED;
        } else if (!this->buttonBack->read()) {
            gateStatus = OPENED;
        }

        this->motor = Motor(motorStatus, gateStatus);

        Serial.println(this->motor.to_string());
    }

public:
    ModeSendDataToApi()
    {
        this->stepper = new Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
        this->stepper->setSpeed(18);

        this->buttonFront = new ButtonDebounce(BUTTON_FRONT);
        this->buttonBack = new ButtonDebounce(BUTTON_BACK);

        this->start();
    }

    void loop()
    {
        this->stepper->step(3);
    }
};

#endif