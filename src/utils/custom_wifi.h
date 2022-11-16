#ifndef _CUSTOM_WIFI_
#define _CUSTOM_WIFI_

#include <WiFi.h>
#include "./models/settings.h"

class CustomWiFi
{
private:
    Settings settings;

    // Função disparada ao connectar ao WiFi
    static void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info)
    {
        Serial.println("Conectando ao WiFi!");
    }

    // Função disparada ao conseguir um Ip na Rede
    static void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info)
    {
        Serial.println("Conectado ao WiFi");
        Serial.println("IP: ");
        Serial.println(WiFi.localIP());
    }

    // Função disparada ao desconnectar ao WiFi
    static void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info)
    {
        Serial.println("Desconectado....");
        Serial.print("Conexão perdida Reason: ");
        Serial.println(info.disconnected.reason);
        Serial.println("Aguarde Reconexão");
    }

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
        WiFi.onEvent(&this->WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
        WiFi.onEvent(&this->WiFiGotIP, SYSTEM_EVENT_STA_GOT_IP);
        WiFi.onEvent(&this->WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);

        WiFi.begin(this->settings.ssid.c_str(), this->settings.password.c_str()); // Inicia a conexão com o WiFi

        WiFi.setAutoReconnect(true);
        WiFi.persistent(true);

        Serial.println("Aguarde pela conexão...");
    }

    bool isConnected() {
        return WiFi.status() == WL_CONNECTED;
    }
};

#endif