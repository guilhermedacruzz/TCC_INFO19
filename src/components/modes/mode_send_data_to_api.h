#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include <Stepper.h>
#include "./mode_basic_sample.h"
#include "./components/widgets/button_debounce.h"
#include "./components/widgets/motor.h"
#include "./utils/enums/motor_status.h"
#include "./utils/web/http_post.h"
#include "./utils/enums/convert_motor_status_to_string.h"

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
    const String endpoint_create = "http://192.168.100.110:3000/logs/create?";
    Stepper stepper = Stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
    ButtonDebounce
        buttonFront = ButtonDebounce(BUTTON_FRONT),
        buttonBack = ButtonDebounce(BUTTON_BACK),
        buttonControl = ButtonDebounce(BUTTON_CONTROL);
    Motor motor;

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
        if(this->motor.getMotorStatus() == CLOSING) {
            this->stepper.step(6);
        }
        else if(this->motor.getMotorStatus() == OPENING) {
            this->stepper.step(-6);
        }

        if(this->motor.hasNewData()) {
            String data = convertMotorStatusToString(this->motor.getMotorStatus());
            String json = this->jsonTools.createSendDataToApi(this->settings, data);
            Serial.println(json);

            String response = httpPost(endpoint_create, json);
            Serial.println(response);

            this->motor.setNewData(false);
        }
    }

public:
    ModeSendDataToApi(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools)  : ModeBasicSample(nonVolatileStorage, jsonTools)
    {
        this->settings = this->nonVolatileStorage.read();
        this->stepper.setSpeed(70);

        this->start();
        
        this->buttonControl.setAction([&] {
            MotorStatus newMotorStatus = (MotorStatus)((this->motor.getMotorStatus() + 1) % 4);
            this->motor.setMotorStatus(newMotorStatus);
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