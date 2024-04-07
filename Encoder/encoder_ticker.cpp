#include <iostream>
#include <ctime>

using namespace std;

class Encoder {
private:
    int pinNumber;
    bool direction;
    int tickCount;
    double radius;
    time_t lastUpdateTime;

public:
    Encoder(int pin, bool dir, double r) : pinNumber(pin), direction(dir), tickCount(0), radius(r) {
        time(&lastUpdateTime);
    }

    void updateTickCount() {
        time_t now;
        time(&now);
        double elapsedTime = difftime(now, lastUpdateTime);

        // Assuming encoder ticks occur every 10 seconds for demonstration purposes
        int ticks = elapsedTime / 10; // Conversion from time to ticks
        if (direction) {
            tickCount += ticks;
        } else {
            tickCount -= ticks;
        }

        time(&lastUpdateTime);
    }

    int getCurrentTickCount() const {
        return tickCount;
    }

    double getCurrentRPM() const {
        // Calculation of RPM
        return (tickCount / 360.0) * 60.0;
    }

    double getCurrentVelocity() const {
        // Assuming velocity is directly proportional to tick count
        // and inversely proportional to the radius
        return (tickCount * 0.1) / radius; // Conversion from ticks to velocity
    }

    void resetTicks() {
        tickCount = 0;
    }
};

// Function to get current tick count
int get_current_tick_count(const Encoder& encoder) {
    return encoder.getCurrentTickCount();
}

// Function to get current RPM
double get_current_rpm(const Encoder& encoder) {
    return encoder.getCurrentRPM();
}

// Function to get current velocity
double get_current_velocity(const Encoder& encoder) {
    return encoder.getCurrentVelocity();
}

// Function to reset ticks
void reset_ticks(Encoder& encoder) {
    encoder.resetTicks();
}

int main() {

    double radius = 0.5; // Example radius
    Encoder motorEncoder(5, true, radius); // Assuming pin 5, clockwise rotation, and radius 0.5 meters
    motorEncoder.updateTickCount(); // Update tick count

    // Output current tick count, RPM, and velocity
    cout << "Current Tick Count: " << get_current_tick_count(motorEncoder) << endl;
    cout << "Current RPM: " << get_current_rpm(motorEncoder) << endl;
    cout << "Current Velocity: " << get_current_velocity(motorEncoder) << endl;

    // Reset tick count
    reset_ticks(motorEncoder);
    cout << "Tick count after reset: " << get_current_tick_count(motorEncoder) << endl;

    return 0;
}
