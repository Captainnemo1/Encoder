#include "Encoder.h"

Encoder::Encoder(int pinA, int pinB) {
    this->pinA = pinA;
    this->pinB = pinB;
    ticks = 0;
    lastTickTime = 0;
}

void Encoder::initialize() {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    attachInterrupt(digitalPinToInterrupt(pinA), tickISR, CHANGE);
}

unsigned long Encoder::get_current_tick_count() {
    return ticks;
}

float Encoder::get_current_rpm() {
    unsigned long currentTime = millis();
    float elapsedTime = (currentTime - lastTickTime) / 60000.0; // Convert milliseconds to minutes
    return ticks / elapsedTime;
}

float Encoder::get_current_velocity() {
    return get_current_rpm() * 2 * PI * RADIUS / 60.0; // Velocity = RPM * 2 * PI * RADIUS (assuming the motor has a fixed radius)
}

void Encoder::reset_ticks() {
    ticks = 0;
}

void Encoder::tickISR() {
    ticks++;
    lastTickTime = millis();
}
