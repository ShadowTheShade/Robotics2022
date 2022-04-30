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

double f(double t, double pos) {
  return max(.5, sin(PI * (pos - t / 20.0))) * 255;
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    double pos = static_cast<double>(i) / (NUM_LEDS) * 4.0;
    leds_blue[i] = CHSV(140, 230, f(time, pos));
    leds_orange[i] = CHSV(35, 250, f(time, pos));
  }
  FastLED.show();
  time++;
}
