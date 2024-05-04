#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <FastLED.h>
#include "image_data.h"

#define NUM_LEDS_PER_STRIP 64
#define DATA_PIN_1 23
#define DATA_PIN_2 18

CRGB leds1[NUM_LEDS_PER_STRIP];
CRGB leds2[NUM_LEDS_PER_STRIP];

void setupLEDs() {
    FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds1, NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds2, NUM_LEDS_PER_STRIP);
}

void displayGlobe(int position) {
    for (int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
        leds1[i] = pgm_read_dword_near(&image_data[i][position]);
        leds2[i] = leds1[i];
    }
    FastLED.show();
}

#endif // LED_CONTROL_H
