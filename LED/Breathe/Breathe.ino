#include <FastLED.h>
#include <math.h>

#define NUM_LEDS 300

#define CHECK_1 4
#define CHECK_2 12
#define BLUE_PIN 3
// #define ORANGE_PIN 5

CRGB leds_blue[NUM_LEDS];
// CRGB leds_orange[NUM_LEDS];

unsigned long int time = 0;

const int D = 9;
int keep_1[D];
int keep_2[D];
unsigned int readhead = 0;

bool reduce_keep() {
  bool res = true;
  for (int i = 1; i < D; i++) {
    res = res && (keep_1[0] == keep_1[i]);
  }
  for (int i = 1; i < D; i++) {
    res = res && (keep_2[0] == keep_2[i]);
  }
  return res;
}


void setup() {
    pinMode(CHECK_1, INPUT);
    pinMode(CHECK_2, INPUT);
    FastLED.addLeds<NEOPIXEL, BLUE_PIN>(leds_blue, NUM_LEDS);  // GRB ordering is assumed
//    FastLED.addLeds<NEOPIXEL, ORANGE_PIN>(leds_orange, NUM_LEDS);  // GRB ordering is assumed
  for (int i = 0; i < D; i++) {
    keep_1[i] = LOW;  
    keep_2[i] = LOW;  
  }
}

void loop() {
  keep_1[readhead] = digitalRead(CHECK_1);
  keep_2[readhead] = digitalRead(CHECK_2);
  readhead = (readhead + 1) % D;
  if (reduce_keep()){
    double f =  abs(fmod(time / 10.0, 2.0) - 1) * 255;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds_blue[i] = CHSV(8, 250, f);
//      leds_orange[i] = CHSV(35, 250, f);
    }
  }
  else {
    double f = (sin(time / 20.0)+ 1) / 2.0 * 255;
    for (int i = 0; i < NUM_LEDS; i++) {
    leds_blue[i] = CHSV(140, 230, f);
//    leds_orange[i] = CHSV(35, 250, f);
  }
  }
  FastLED.show();
  time++;
}
