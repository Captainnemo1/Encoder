// Encoder.h

#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder {
private:
    volatile int pinA;
    volatile int pinB;
    volatile unsigned long ticks;
    volatile unsigned long lastTickTime;

public:
    Encoder(int pinA, int pinB);
    void initialize();
    unsigned long get_current_tick_count();
    float get_current_rpm();
    float get_current_velocity();
    void reset_ticks();

private:
    static void tickISR();
};

#endif
