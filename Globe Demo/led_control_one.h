#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 64
#define DATA_PIN 2
#define BRIGHTNESS 128
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS_PER_STRIP];

void setupLEDs() {
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  static uint8_t hue = 0;
  // Create a rainbow that uniformly distributes itself across all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 256 / NUM_LEDS), 255, 255);
  }
  FastLED.show();
  hue++;
  delay(20); // Adjust for speed
}

/* Testing for White Color on LEDs to determine maximum current required for the power supply
void loop() {
  fill_solid(leds, NUM_LEDS, CRGB::White); // Set all LEDs to white
  FastLED.show();
  delay(1000); // Optional delay, adjust or remove as needed
}*/
