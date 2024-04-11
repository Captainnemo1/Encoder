#include <Encoder.h>

const int ENCODER_PIN_A = 2; // Replace with the actual pin numbers connected to the encoder
const int ENCODER_PIN_B = 3;
Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
    Serial.begin(9600);
    encoder.initialize();
}

void loop() {
    Serial.print("Tick count: ");
    Serial.println(encoder.get_current_tick_count());
    Serial.print("RPM: ");
    Serial.println(encoder.get_current_rpm());
    Serial.print("Velocity: ");
    Serial.println(encoder.get_current_velocity());
    delay(1000);
}
