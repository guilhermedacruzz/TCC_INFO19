#ifndef _MODE_CONFIGURATION_
#define _MODE_CONFIGURATION_

#include "mode_basic_sample.h"

class ModeConfiguration : public ModeBasicSample
{
public:
    ModeConfiguration()
    {
        Serial.println("Modo Configuração");
    }

    void loop()
    {
        Serial.println("Loop Configuração");
        delay(5000);
    }
};

#endif