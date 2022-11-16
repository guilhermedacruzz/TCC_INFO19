#ifndef _MODE_CONFIGURATION_
#define _MODE_CONFIGURATION_

#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "mode_basic_sample.h"
#include "./models/settings.h"
#include "./utils/non_volatile_storage.h"
#include "./utils/json_tools.h"

AsyncWebServer server(80);
bool status = false;
String body;

class ModeConfiguration : public ModeBasicSample
{

private:
    const char *assid = "Teste12345";
    const char *asecret = "12345678";

    NonVolatileStorage *nonVolatileStorage;
    JsonTools *jsonTools;

public:
    ModeConfiguration(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools)
    {

        this->nonVolatileStorage = nonVolatileStorage;
        this->jsonTools = jsonTools;

            Serial.println("Iniciando modo de configuração!");
        WiFi.mode(WIFI_MODE_AP); // Modifica o modo do WiFi para Access Point

        Serial.println("Criando ponto de acesso....");
        WiFi.softAP(this->assid, this->asecret);

        // Inicializa o server que recebe das configurações
        server.on(
            "/hello",
            HTTP_POST,
            [](AsyncWebServerRequest *request) {},
            NULL,
            [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
            {
                size_t i;
                char mensage[len];

                for (i = 0; i < len; i++)
                {
                    mensage[i] = data[i];
                }
                mensage[i] = '\0';

                status = true;
                body = mensage;
                request->send(200, "text/plain", "Ok! ");
            });

        Serial.print("Iniciando server no ip: ");
        Serial.println(WiFi.softAPIP());

        server.begin();
    }

    void loop()
    {
        if (status)
        {
            Settings settings = this->jsonTools->deserialize(body);

            this->nonVolatileStorage->write(settings);

            Serial.println(settings.to_string());

            status = false;
        }
    }
};

#endif