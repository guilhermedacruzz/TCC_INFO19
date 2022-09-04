#ifndef _BUTTONDEBOUNCE_
#define _BUTTONDEBOUNCE_

#define TIMEDEBOUNCE 50

class ButtonDebounce
{
public:
  bool isClicked = false;
  int stateButton;
  int stateButtonPrevious = LOW;
  unsigned long timeLastDebounce = 0;
  int PIN;

  ButtonDebounce(int PIN)
  {
    this->PIN = PIN;
    pinMode(this->PIN, INPUT_PULLUP);
  }

  void read()
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
          isClicked = !isClicked;
        }
      }
    }

    stateButtonPrevious = reading;
  }
};

#endif