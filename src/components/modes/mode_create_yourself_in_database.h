#ifndef _MODE_CREATE_YOURSELF_IN_DATABASE_
#define _MODE_CREATE_YOURSELF_IN_DATABASE_

#include <WiFi.h>
#include "mode_basic_sample.h"
#include "./models/settings.h"
#include "./utils/nvs.h"
#include "./utils/custom_wifi.h"

extern NVS nvs;
extern CustomWiFi wifi;

class ModeCreateYourselfInDatabase : public ModeBasicSample
{

private:


public:
    ModeCreateYourselfInDatabase()
    {
        
    }

    void loop()
    {

    }
};

#endif
