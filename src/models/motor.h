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
    Motor() {}

    Motor(MotorStatus motorStatus, GateStatus gateStatus)
    {
        this->motorStatus = motorStatus;
        this->gateStatus = gateStatus;
    }

    GateStatus getGateStatus() {
        return this->gateStatus;
    }

    MotorStatus getMotorStatus() {
        return this->motorStatus;
    }

    void setMotorStatus(MotorStatus motorStatus) {
        this->motorStatus = motorStatus;
    }

    void setGateStatus(GateStatus gateStatus) {
        this->gateStatus = gateStatus;
    }

    String to_string()
    {
        return String("MotorStatus: ") + this->motorStatus +
               String(" GateStatus: ") + this->gateStatus;
    }
};

#endif