#ifndef _MODE_BASIC_SAMPLE_
#define _MODE_BASIC_SAMPLE_
#include "./utils/web/json_tools.h"
#include "./utils/nvs/non_volatile_storage.h"
#include "./utils/web/custom_wifi.h"
#include "./models/settings.h"

class ModeBasicSample
{
protected:
    NonVolatileStorage nonVolatileStorage;
    JsonTools jsonTools;
    Settings settings;
    CustomWiFi wifi;

public:
    ModeBasicSample(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools)
    {
        this->nonVolatileStorage = *nonVolatileStorage;
        this->jsonTools = *jsonTools;
    }

    virtual void loop() {}
};

#endif