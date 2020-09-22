#include <LED/LED.h>

LED::LED(const int pin) : pin(pin)
{
    pinMode(pin, OUTPUT);
}
