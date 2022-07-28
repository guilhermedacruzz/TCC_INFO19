#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "post.h"
#include "message.h"
#include "encode.h"

extern void postData(String url);

const char *ssid = "";
const char *password = "";

String apiKey = "";
String phone_number = "";

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Conectando no Wifi...");
  }
  Serial.println("Conectado na Rede Wifi!");

  messageWhatsapp("This is a test");
}

void loop() {}
