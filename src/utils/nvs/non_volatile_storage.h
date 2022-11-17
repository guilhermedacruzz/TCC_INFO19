#ifndef _NON_VOLATILE_STORAGE_
#define _NON_VOLATILE_STORAGE_

#include <Preferences.h>
#include "../src/models/settings.h"

class NonVolatileStorage
{
private:
    Preferences preferences;
    const char *nameSpace = "sapa";

public:
    NonVolatileStorage() {}

    bool check(const char *value)
    {
        this->preferences.begin(this->nameSpace, true);

        String result = this->preferences.getString(value);

        this->preferences.end();

        return !result.compareTo("") == 0;
    }

    void write(Settings settings)
    {
        this->preferences.begin(this->nameSpace, false);

        this->preferences.clear();

        if (settings.id != String())
        {
            this->preferences.putString("id", settings.id);
        }

        this->preferences.putString("name", settings.name);
        this->preferences.putString("description", settings.description);
        this->preferences.putString("user_id", settings.user_id);
        this->preferences.putInt("timer", settings.timer);
        this->preferences.putString("ssid", settings.ssid);
        this->preferences.putString("password", settings.password);

        this->preferences.end();
    }

    Settings read()
    {
        this->preferences.begin(this->nameSpace, true);

        Settings settings(
            this->preferences.getString("id"),
            this->preferences.getString("name"),
            this->preferences.getString("description"),
            this->preferences.getString("user_id"),
            this->preferences.getInt("timer"),
            this->preferences.getString("ssid"),
            this->preferences.getString("password"));

        this->preferences.end();

        return settings;
    }

    void clear()
    {
        this->preferences.begin(this->nameSpace, false);

        this->preferences.clear();

        this->preferences.end();
    }
};

#endif