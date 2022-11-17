#ifndef _MOTOR_
#define _MOTOR_

#include "./utils/enums/motor_status.h"
#include "./utils/enums/gate_status.h"

class Motor
{

private:
    MotorStatus motorStatus;
    GateStatus gateStatus;

public:
    Motor(MotorStatus motorStatus, GateStatus gateStatus)
    {
        this->motorStatus = motorStatus;
        this->gateStatus = gateStatus;
    }
};

#endif