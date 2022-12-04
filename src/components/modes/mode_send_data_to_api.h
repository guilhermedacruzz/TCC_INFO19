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
    Settings settings;
    CustomWiFi wifi;
    Stepper stepper = Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
    ButtonDebounce
        buttonFront = ButtonDebounce(BUTTON_FRONT),
        buttonBack = ButtonDebounce(BUTTON_BACK),
        buttonControl = ButtonDebounce(BUTTON_CONTROL);
    Motor motor;
    MotorStatus currentMotorStatus = CLOSING;

    void start()
    {
        MotorStatus motorStatus = STOPED_OPENING;

        if (this->buttonFront.read())
        {
            motorStatus = STOPED_CLOSING;
        }
        this->motor = Motor(motorStatus);
    }

    void running() {
        MotorStatus motorStatus = this->motor.getMotorStatus();

        if(motorStatus == CLOSING) {
            this->stepper.step(4);
        }
        else if(motorStatus == OPENING) {
            this->stepper.step(-4);
        }
    }

public:
    ModeSendDataToApi(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools)  : ModeBasicSample(nonVolatileStorage, jsonTools)
    {
        wifi = CustomWiFi(this->settings);
        wifi.connect();

        this->settings = this->nonVolatileStorage.read();
        this->stepper.setSpeed(70);

        this->start();
        
        this->buttonControl.setAction([&] {
            this->motor.setMotorStatus((MotorStatus)((this->motor.getMotorStatus() + 1) % 4));
            String json = this->jsonTools.createSendDataToApi(this->settings, this->motor.getMotorStatus());
            Serial.println(json);
        });

        this->buttonFront.setAction([&] {
            this->motor.setMotorStatus(STOPED_CLOSING);
        });
        this->buttonBack.setAction([&] {
            this->motor.setMotorStatus(STOPED_OPENING);
        });
        wifi = CustomWiFi(this->settings);
        wifi.connect();
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