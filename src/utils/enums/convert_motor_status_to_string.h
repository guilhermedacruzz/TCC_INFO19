#ifndef _CONVERT_MOTOR_STATUS_TO_STRING_
#define _CONVERT_MOTOR_STATUS_TO_STRING_

#include "Arduino.h"
#include <list>
#include "./motor_status.h"

String convertMotorStatusToString(MotorStatus motorstatus) {
    return std::vector<String> {"Fechando", "Fechado", "Abrindo", "Aberto"}.at((int) motorstatus);
}

#endif