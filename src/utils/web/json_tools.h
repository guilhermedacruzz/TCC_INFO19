#ifndef _JSON_TOOLS_
#define _JSON_TOOLS_

#include <typeinfo>
#include <ArduinoJson.h>
#include "./models/settings.h"

class JsonTools
{
public:
    JsonTools() {}

    Settings deserialize(String body)
    {
        DynamicJsonDocument doc(1024);

        deserializeJson(doc, body);

        JsonObject obj = doc.as<JsonObject>();

        return Settings(
            (obj["id"].as<String>() != "null" ? obj["id"] : String()),
            obj["name"],
            obj["description"],
            obj["user_id"],
            obj["timer"],
            obj["ssid"],
            obj["password"]);
    }

    String createYourselfInDatabase(Settings settings)
    {
        return "{\"name\":\"" + settings.name + "\","
               "\"description\":\"" + settings.description + "\","
               "\"user\":\"" + settings.user_id + "\""
               //"\"timer\":" + settings.timer + 
               "}";
    }

    String createSendDataToApi()
    {
        return "";
    }
};

#endif