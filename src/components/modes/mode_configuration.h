#ifndef _MODE_CONFIGURATION_
#define _MODE_CONFIGURATION_

#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "mode_basic_sample.h"
#include "./models/settings.h"
#include "./utils/nvs/non_volatile_storage.h"
#include "./utils/web/json_tools.h"

class ModeConfiguration : public ModeBasicSample
{

private:
    const char *assid = "Teste12345";
    const char *asecret = "12345678";

    AsyncWebServer server = AsyncWebServer(80);
    bool hasMensage = false;
    String body;

public:
    ModeConfiguration(NonVolatileStorage *nonVolatileStorage, JsonTools *jsonTools) : ModeBasicSample(nonVolatileStorage, jsonTools)
    {
        
        Serial.println("Iniciando modo de configuração!");
        WiFi.mode(WIFI_MODE_AP); // Modifica o modo do WiFi para Access Point

        Serial.println("Criando ponto de acesso....");
        WiFi.softAP(this->assid, this->asecret);

        // Inicializa o server que recebe das configurações
        this->server.on(
            "/hello",
            HTTP_POST,
            [](AsyncWebServerRequest *request) {},
            NULL,
            [&](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
            {
                size_t i;
                char mensage[len];

                for (i = 0; i < len; i++)
                {
                    mensage[i] = data[i];
                }
                mensage[i] = '\0';

                this->hasMensage = true;
                this->body = mensage;
                request->send(200, "text/plain", "Ok!");
            });

        Serial.print("Iniciando server no ip: ");
        Serial.println(WiFi.softAPIP());

        this->server.begin();
    }

    void loop()
    {
        if (this->hasMensage)
        {
            Settings settings = this->jsonTools.deserialize(this->body);

            this->nonVolatileStorage.write(settings);

            Serial.println(this->nonVolatileStorage.read().to_string());

            ESP.restart();
        }
    }
};

#endif