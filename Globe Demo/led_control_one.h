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

void updatePattern() {
    static uint8_t startIndex = 0;
    startIndex++;  // Makes the pattern move

    // Defining smooth-transition colors
    CRGB color1 = CRGB::Blue;      // Start with Blue
    CRGB color2 = CRGB::Aqua;      // Transition to Aqua
    CRGB color3 = CRGB::Green;     // End with Green

    for (int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
        int pos = (startIndex + i) % NUM_LEDS_PER_STRIP;  // Total length of the LED strip

        if (pos < (NUM_LEDS_PER_STRIP / 3)) {  // First color to second color
            leds[i] = blend(color1, color2, pos * 3);  // Smooth blend
        } else if (pos < (2 * NUM_LEDS_PER_STRIP / 3)) {  // Second color to third color
            leds[i] = blend(color2, color3, (pos - NUM_LEDS_PER_STRIP / 3) * 3);  // Continue blending
        } else {  // Third color back to first
            leds[i] = blend(color3, color1, (pos - 2 * NUM_LEDS_PER_STRIP / 3) * 3);
        }
    }
}

#endif // LED_CONTROL_H
