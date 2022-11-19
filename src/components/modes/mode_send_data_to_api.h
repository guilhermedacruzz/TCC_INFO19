#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include <Stepper.h>
#include "./mode_basic_sample.h"
#include "./components/widgets/button_debounce.h"
#include "./models/motor.h"
#include "./utils/enums/motor_status.h"
#include "./utils/enums/gate_status.h"

const int stepsPerRevolution = 512;

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
        MotorStatus motorStatus = STOPED_OPENING;

        if (!this->buttonFront.read())
        {
            Serial.println("Entrou!");
            motorStatus = STOPED_CLOSING;
        }

        this->motor = Motor(motorStatus);
    }

    void running() {
        if(this->motor.getMotorStatus() == CLOSING) {
            this->stepper.step(4);
        }
        else if((this->motor.getMotorStatus() == OPENING)) {
            this->stepper.step(-4);
        }
    }

public:
    ModeSendDataToApi()
    {
        this->stepper.setSpeed(20);

        this->start();
        
        this->buttonControl.setAction([&] {
            this->motor.setMotorStatus((MotorStatus)((this->motor.getMotorStatus() + 1) % 4));
            Serial.println(this->motor.getMotorStatus());
        });

        this->buttonFront.setAction([&] {
            this->motor.setMotorStatus(STOPED_CLOSING);
        });

        this->buttonBack.setAction([&] {
            this->motor.setMotorStatus(STOPED_OPENING);
        });
    }

    void loop()
    {
        this->running();
        this->buttonControl.execute();
        this->buttonFront.execute();
        this->buttonBack.execute();
    }
};

#endif