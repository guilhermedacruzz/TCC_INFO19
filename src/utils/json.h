#ifndef _JSON_
#define _JSON_

#include <typeinfo>
#include <ArduinoJson.h>
#include "./models/settings.h"

class Json
{
public:
    Json() {}

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
        return "{\"name\":" + settings.name +
               "\"description\":" + settings.description +
               "\"user_id\":" + settings.user_id +
               "\"timer\":" + settings.timer + "}";
    }

    String createSendDataToApi()
    {
        return "";
    }
};

#endif