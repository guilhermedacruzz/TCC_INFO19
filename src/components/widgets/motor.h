#ifndef _MOTOR_
#define _MOTOR_

#include <Arduino.h>
#include "./utils/enums/motor_status.h"

class Motor
{

private:
    MotorStatus motorStatus;
    bool newData = false;

public:
    Motor() {}

    Motor(MotorStatus motorStatus)
    {
        this->motorStatus = motorStatus;
    }

    MotorStatus getMotorStatus() {
        return this->motorStatus;
    }

    void setMotorStatus(MotorStatus motorStatus) {
        this->motorStatus = motorStatus;
        newData = true;
    }

    bool hasNewData() {
        return newData;
    }

    void setNewData(bool newData) {
        this->newData = newData;
    }

    String to_string()
    {
        return String("MotorStatus: ") + this->motorStatus;
    }
};

#endif