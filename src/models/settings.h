#ifndef _SETTINGS_
#define _SETTINGS_

#include <iostream>

class Settings
{
    public:
        String id;
        String name;
        String description;
        String user_id;
        int timer;
        String ssid;
        String password;

        Settings(){}

        Settings(String id, String name, String description, String user_id, int timer, String ssid, String password)
        {
            this->id = id;
            this->name = name;
            this->description = description;
            this->user_id = user_id;
            this->timer = timer;
            this->ssid = ssid;
            this->password = password;
        }

        Settings(String name, String description, String user_id, int timer, String ssid, String password)
        {
            this->id = String();
            this->name = name;
            this->description = description;
            this->user_id = user_id;
            this->timer = timer;
            this->ssid = ssid;
            this->password = password;
        }
        
        String to_string() {
            return String("id: ") + this->id + \
            String(" name: ") + this->name + \
            String(" description: ") + this->description + \
            String(" user_id: ") + this->user_id + \
            String(" timer: ") + this->timer + \
            String(" ssid: ") + this->ssid + \
            String(" password: ") + this->password;
        }
};

#endif