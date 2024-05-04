#include <Arduino.h>
#include <FastLED.h>
#include "led_control.h" // Dual Pattern "led_control_one.h" for single-sided

void setup() {
    Serial.begin(115200);
    setupLEDs();  // Setup LED strips
}

void loop() {
    updatePattern();
    FastLED.show();
    delay(50);  // Delay to control the speed of the animation
}
