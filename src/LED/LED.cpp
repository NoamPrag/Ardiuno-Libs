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

void LED::fade(const int start = 0, const int end = 255, const int time) {
    static int brightness = start;

    static const int fadeAmount = (end - start) / time;

    const unsigned long int time = millis();
    static unsigned long int prevTime = time;

    brightness += (time - prevTime) * fadeAmount;

    setBrightness(brightness);

    prevTime = time;
}
