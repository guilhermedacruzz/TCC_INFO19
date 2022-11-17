#ifndef _MODE_SEND_DATA_TO_API_
#define _MODE_SEND_DATA_TO_API_

#include <Arduino.h>
#include "./mode_basic_sample.h"

class ModeSendDataToApi : public ModeBasicSample{

    private:
        const int stepsPerRevolution = 500;

    public:
        ModeSendDataToApi(){}

        void loop() {
            Serial.println("teste");
        }

};

#endif