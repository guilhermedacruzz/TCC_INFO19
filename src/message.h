#ifndef _MESSAGE_
#define _MESSAGE_

#include <Arduino.h>

void messageWhatsapp(String message);

extern void postData(String url);
extern String urlEncode(String str);

extern String phone_number;
extern String apiKey;

void messageWhatsapp(String message)
{
    String url = "https://api.callmebot.com/whatsapp.php?phone=" + phone_number + "&text=" + urlEncode(message) + "&apikey=" + apiKey;
    Serial.println("Enviando a mensagem!");
    //postData(url);
}

#endif
