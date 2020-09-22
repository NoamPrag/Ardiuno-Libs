#include <Arduino.h>

class LED
{
private:
    const int pin;
    bool ledState;
    long changeTime;

    void write()
    {
        digitalWrite(pin, ledState);
    }

public:
    LED(const int pin);

    void on()
    {
        this->ledState = HIGH;
        this->changeTime = millis();
        write();
    }

    void off()
    {
        changeTime = millis();
        this->ledState = LOW;
        write();
    }

    void blink(const int onTime, const int offTime)
    {
        if (this->ledState)
        {
            if (millis() - this->changeTime >= onTime)
            {
                off();
            }
        }
        else if (millis() - this->changeTime >= offTime)
        {
            on();
        }
    }

    void setBrightness(const int brightness)
    {
        analogWrite(pin, brightness);
    }
};
