#ifndef _BUTTON_DEBOUNCE_
#define _BUTTON_DEBOUNCE_

#include <Arduino.h>

#define TIMEDEBOUNCE 50

typedef void (*Action)();

class ButtonDebounce
{
    public:
        int stateButton;
        int stateButtonPrevious = LOW;
        unsigned long timeLastDebounce = 0;
        int PIN;

        ButtonDebounce(int PIN)
        {
            this->PIN = PIN;
            pinMode(this->PIN, INPUT_PULLUP);
        }

        void read(Action action)
        {
            int reading = digitalRead(PIN);

            if (reading != stateButtonPrevious)
            {
                timeLastDebounce = millis();
            }

            if ((millis() - timeLastDebounce) > TIMEDEBOUNCE)
            {
                if (reading != stateButton)
                {
                    stateButton = reading;
                    if (stateButton == LOW)
                    {
                        action();
                    }
                }
            }

            stateButtonPrevious = reading;
        }
};

#endif