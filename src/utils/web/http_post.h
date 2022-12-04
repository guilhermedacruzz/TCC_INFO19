#ifndef _HTTP_POST_
#define _HTTP_POST_

#include <HTTPClient.h>

// Protótipos de Função
String httpPost(String endpoint, String body);

// Função por fazer o post http
String httpPost(String endpoint, String body)
{
    String response = "";

    HTTPClient http;

    http.begin(endpoint);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(body);
    Serial.println("Status Code: " + httpResponseCode);

    response = http.getString();

    http.end();

    return response;
}
#endif