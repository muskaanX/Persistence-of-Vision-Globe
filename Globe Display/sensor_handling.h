#ifndef SENSOR_HANDLING_H
#define SENSOR_HANDLING_H

volatile bool magnetDetected = false;

void IRAM_ATTR onMagnetDetected() {
    magnetDetected = true;
}

void setupSensor() {
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), onMagnetDetected, FALLING);
}

int currentPosition() {
    // Placeholder for function to calculate position based on sensor input
    return 0;
}

#endif // SENSOR_HANDLING_H
