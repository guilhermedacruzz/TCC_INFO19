#ifndef _MOTOR_
#define _MOTOR_

enum MotorStatus
{
    STOPED,
    OPENING,
    CLOSING
};

enum GateStatus
{
    CLOSED,
    RUNNIG,
    OPENED
};

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