#ifndef _MODE_CREATE_YOURSELF_IN_DATABASE_
#define _MODE_CREATE_YOURSELF_IN_DATABASE_

#include <WiFi.h>
#include "mode_basic_sample.h"
#include "./models/settings.h"
#include "./utils/nvs/non_volatile_storage.h"
#include "./utils/web/http_post.h"
#include "./utils/web/custom_wifi.h"
#include "./utils/web/json_tools.h"

class ModeCreateYourselfInDatabase : public ModeBasicSample
{

private:
    const String endpoint_create = "http://192.168.100.110:3000/iots/create";

public:
    ModeCreateYourselfInDatabase(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools) : ModeBasicSample(nonVolatileStorage, jsonTools)
    {
        this->settings = this->nonVolatileStorage.read();
        wifi = CustomWiFi(this->settings);
        wifi.connect();
    }

    void loop()
    {
        if (wifi.isConnected())
        {
            Serial.println("Enviando informações para a API..");
            Serial.print("URL: ");
            Serial.println(this->endpoint_create);

            String body = this->jsonTools.createYourselfInDatabase(this->settings); // Cria o json do patch
            Serial.print("JSON: ");
            Serial.println(body);
            //String response = httpPost(endpoint_create, body); // Faz o patch para a api
            String response = "";
            Serial.print("RESPOSTA: ");
            Serial.println(response);

            if (!response.compareTo("") == 0)
            {
                Settings settings = this->jsonTools.deserialize(response);

                this->nonVolatileStorage.write(settings);

                Serial.println("Reiniciando....");
                delay(2000);
                //ESP.restart();
            }
        }
    }
};

#endif
