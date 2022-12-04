#ifndef _MODE_BASIC_SAMPLE_
#define _MODE_BASIC_SAMPLE_
#include "./utils/web/json_tools.h"
#include "./utils/nvs/non_volatile_storage.h"

class ModeBasicSample
{
protected:
    NonVolatileStorage nonVolatileStorage;
    JsonTools jsonTools;

public:
    ModeBasicSample(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools)
    {
        this->nonVolatileStorage = *nonVolatileStorage;
        this->jsonTools = *jsonTools;
    }

    virtual void loop() {}
};

#endif