#ifndef _POST_
#define _POST_

#include <HTTPClient.h>

void postData(String url);

void postData(String url) 
{
    int httpCode;
    HTTPClient http;
    http.begin(url);
    httpCode = http.POST(url); // Fazendo o Post
    if (httpCode == 200) // Verifica se o código de retorno é 200
    {
        Serial.println("Sent ok.");
    }
    else 
    {
        Serial.println("Error.");
    }
    http.end();
}

#endif