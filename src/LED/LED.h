#include <Arduino.h>

class LED
{
private:
    const int pin;
    bool ledState;
    long changeTime;

    void write();

public:
    LED(const int pin);

    void on();

    void off();

    void blink(const int onTime, const int offTime);

    void setBrightness(const int brightness);

    void fade(const int start, const int end, const int time);
};
