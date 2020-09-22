#include <LED/LED.h>

LED::LED(const int pin) : pin(pin)
{
    pinMode(pin, OUTPUT);
}

void LED::write()
{
    digitalWrite(this->pin, this->ledState);
}

void LED::on()
{
    this->ledState = HIGH;
    this->changeTime = millis();
    write();
}

void LED::off()
{
    changeTime = millis();
    this->ledState = LOW;
    write();
}

void LED::blink(const int onTime, const int offTime)
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

void LED::setBrightness(const int brightness)
{
    analogWrite(this->pin, brightness);
}