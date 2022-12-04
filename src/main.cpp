#include <Arduino.h>
#include <Stepper.h>
#include "./components/widgets/button_debounce.h"
#include "./utils/nvs/non_volatile_storage.h"
#include "models/settings.h"
#include "components/modes/mode_basic_sample.h"
#include "components/modes/mode_configuration.h"
#include "components/modes/mode_create_yourself_in_database.h"
#include "components/modes/mode_send_data_to_api.h"
#include "./utils/web/custom_wifi.h"

#define BUTTON_RESET 32

ModeBasicSample *mode;
ButtonDebounce buttonReset(BUTTON_RESET);

void setup()
{
    Serial.begin(115200);

    NonVolatileStorage nonVolatileStorage;
    nonVolatileStorage.write(Settings("63813cb124c47da64ebec329", "name", "description", "user_id", 3, "2.4g Adalberto", "qi2001to500"));
    JsonTools jsonTools;

    if (!nonVolatileStorage.check("name"))
    {
        mode = new ModeConfiguration(&nonVolatileStorage, &jsonTools);
    }
    else
    {
        if(!nonVolatileStorage.check("id")) {
            mode = new ModeCreateYourselfInDatabase(&nonVolatileStorage, &jsonTools);
        } else {
            mode = new ModeSendDataToApi(&nonVolatileStorage, &jsonTools);
        }
    }

    buttonReset.setAction([] {
        Serial.println("Resetando....");
        NonVolatileStorage().clear();
        ESP.restart();
    });

    delay(500);
}

void loop()
{
    mode->loop();
    buttonReset.execute();
}