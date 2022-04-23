#include <FastLED.h>

#define NUM_LEDS 300

#define BLUE_PIN 3
#define ORANGE_PIN 5

CRGB leds_blue[NUM_LEDS];
CRGB leds_orange[NUM_LEDS];

unsigned long int time = 0;

void setup() { 
    FastLED.addLeds<NEOPIXEL, BLUE_PIN>(leds_blue, NUM_LEDS);  // GRB ordering is assumed
    FastLED.addLeds<NEOPIXEL, ORANGE_PIN>(leds_orange, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {
  double f = (sin(time / 10.0)+ 1) / 2.0 * 255;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_blue[i] = CHSV(140, 230, f);
    leds_orange[i] = CHSV(35, 250, f);
  }
  FastLED.show();
  time++;
}
