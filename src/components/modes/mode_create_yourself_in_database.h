#ifndef _MODE_CREATE_YOURSELF_IN_DATABASE_
#define _MODE_CREATE_YOURSELF_IN_DATABASE_

#include <WiFi.h>
#include "mode_basic_sample.h"
#include "./models/settings.h"
#include "./utils/nvs.h"
#include "./utils/custom_wifi.h"
#include "./utils/json.h"

extern NVS nvs;
extern CustomWiFi wifi;
extern Json json;

class ModeCreateYourselfInDatabase : public ModeBasicSample
{

private:
    Settings settings;
    const String endpoint_create = "testeeeeeee";

public:
    ModeCreateYourselfInDatabase()
    {
        this->settings = nvs.read();
        Serial.println(this->settings.to_string());
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

            String body = json.createYourselfInDatabase(this->settings); // Cria o json do patch
            Serial.print("JSON: ");
            Serial.println(body);
            // String response = httpPost(endpoint_create, jsonData); // Faz o patch para a api
            Serial.print("RESPOSTA: ");
            // Serial.println(response);

            /*
            if (!response.compareTo("") == 0)
            {                                    // verifica se obteve resposta
                //deserializeIdentifier(response); // Deserializa a resposta
                //writeIdentifier();               // Salva na memória permanente

                Serial.println("Identificador da lixeira gravado com sucesso!");
                Serial.println("Reiniciando....");
                delay(2000);
                ESP.restart(); // Reinicia
            }*/

            delay(2000);
        }
    }
};

#endif
