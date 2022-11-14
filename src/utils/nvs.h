#ifndef _NVS_
#define _NVS_

#include <Preferences.h>
#include "../src/models/settings.h"

class NVS
{
    public:
        Preferences preferences;
        const char *nameSpace = "sapa";

        bool check(const char *value)
        {
            preferences.begin(nameSpace, true);

            String result = preferences.getString(value);

            preferences.end();

            return !result.compareTo("") == 0;
        }

        void write(Settings settings)
        {
            preferences.begin(nameSpace, false);

            preferences.clear();

            if(settings.id != String()) {
                preferences.putString("id", settings.id);
            }

            preferences.putString("name", settings.name);
            preferences.putString("description", settings.description);
            preferences.putString("user_id", settings.user_id);
            preferences.putInt("timer", settings.timer);
            preferences.putString("ssid", settings.ssid);
            preferences.putString("password", settings.password);

            preferences.end();
        }

        Settings read() {
            preferences.begin(nameSpace, true);

            Settings settings(
                preferences.getString("id"),
                preferences.getString("name"),
                preferences.getString("description"),
                preferences.getString("user_id"),
                preferences.getInt("timer"),
                preferences.getString("ssid"),
                preferences.getString("password")
            );

            preferences.end();

            return settings;
        }

        void clear()
        {
            preferences.begin(nameSpace, false);

            preferences.clear();

            preferences.end();
        }
};

#endif