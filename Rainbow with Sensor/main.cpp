#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 64
#define DATA_PIN 2
#define BRIGHTNESS 128
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

void setupLEDs() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(HALL_SENSOR_PIN, INPUT);
}

void loop() {
  static uint8_t hue = 0;
  int sensorState = digitalRead(HALL_SENSOR_PIN);
  
  if (sensorState == LOW) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(hue + (i * 256 / NUM_LEDS), 255, 255);
    }
    FastLED.show();
    hue++;
    delay(20); // Adjust for speed
  }

  else {
    for (int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }
}
