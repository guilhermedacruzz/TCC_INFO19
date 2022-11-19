#ifndef _MOTOR_
#define _MOTOR_

#include "./utils/enums/motor_status.h"
#include "./utils/enums/gate_status.h"

class Motor
{

private:
    MotorStatus motorStatus;

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
    }


    String to_string()
    {
        return String("MotorStatus: ") + this->motorStatus;
    }
};

#endif