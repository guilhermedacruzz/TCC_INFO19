#ifndef _BUTTON_DEBOUNCE_
#define _BUTTON_DEBOUNCE_

#include <Arduino.h>
#include <functional>

typedef std::function<void(void)> Action;

#define TIMEDEBOUNCE 50

class ButtonDebounce
{
private:
    int stateButton;
    int stateButtonPrevious = LOW;
    unsigned long timeLastDebounce = 0;
    int PIN;
    Action action;

public:
    ButtonDebounce() {}

    ButtonDebounce(int PIN)
    {
        this->PIN = PIN;
        pinMode(this->PIN, INPUT_PULLUP);
    }

    bool read()
    {
        return digitalRead(PIN);
    }

    void setAction(Action action)
    {
        this->action = action;
    }

    void execute()
    {
        int reading = this->read();

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
                    this->action();
                }
            }
        }

        stateButtonPrevious = reading;
    }
};

#endif