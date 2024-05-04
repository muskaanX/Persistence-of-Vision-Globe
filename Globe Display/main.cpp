#include <Arduino.h>
#include "led_control.h"
#include "sensor_handling.h"
#include "wifi_control.h"

void setup() {
    Serial.begin(115200);
    setupWiFi();  // Setup WiFi connection
    setupLEDs();  // Setup LED strips
    setupSensor();  // Setup Hall effect sensor
}

void loop() {
    if (magnetDetected) {
        displayGlobe(currentPosition());  // Display the globe image depending on the sensor position
        magnetDetected = false;  // Reset the detection flag
    }
    handleClient();  // Handle any incoming Wi-Fi clients (for web server)
}
