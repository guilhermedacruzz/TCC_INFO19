#ifndef _CUSTOM_WIFI_
#define _CUSTOM_WIFI_

#include "Arduino.h"
#include <WiFi.h>
#include "./models/settings.h"

class CustomWiFi
{
private:
    Settings settings;

public:
    CustomWiFi() {}

    CustomWiFi(Settings settings)
    {
        this->settings = settings;
    }

    void connect()
    {
        WiFi.disconnect(true); // Tenta desconnectar do Wifi, apenas questão de segurança e limpeza

        delay(1000);

        // Configura os eventos do WiFi
        WiFi.onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info) { 
            Serial.println("Conectando ao WiFi!"); 
        }, ARDUINO_EVENT_WIFI_STA_CONNECTED); // Função disparada ao connectar ao WiFi

        WiFi.onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info) {
            Serial.println("Conectado ao WiFi");
            Serial.println("IP: ");
            Serial.println(WiFi.localIP()); 
        }, ARDUINO_EVENT_WIFI_STA_GOT_IP); // Função disparada ao conseguir um Ip na Rede

        WiFi.onEvent([&](WiFiEvent_t event, WiFiEventInfo_t info) {
            Serial.println("Desconectado....");
            Serial.print("Conexão perdida Reason: ");
            Serial.println(info.wifi_sta_disconnected.reason);
            Serial.println("Aguarde Reconexão");
            WiFi.begin(this->settings.ssid.c_str(), this->settings.password.c_str());
        }, ARDUINO_EVENT_WIFI_STA_DISCONNECTED); // Função disparada ao desconnectar ao WiFi

        WiFi.begin(this->settings.ssid.c_str(), this->settings.password.c_str()); // Inicia a conexão com o WiFi

        Serial.println("Aguarde pela conexão...");
    }

    bool isConnected()
    {
        return WiFi.status() == WL_CONNECTED;
    }
};

#endif