#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "";
const char *password = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando no Wifi...");
  }
  Serial.println("Conectado na Rede Wifi!");
}

void loop() {}