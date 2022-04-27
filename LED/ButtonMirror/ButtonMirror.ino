#include <FastLED.h>
#define PIN        9


#define NUM_LEDS 300

#define BLUE_PIN 3
#define ORANGE_PIN 5

CRGB leds_blue[NUM_LEDS];
CRGB leds_orange[NUM_LEDS];

unsigned long int time = 0;

CRGB leds[NUM_LEDS];
int myPin = 7;

const int D = 5;
int keep[D];
unsigned int readhead = 0;

bool reduce_keep() {
  bool res = true;
  for (int i = 1; i < D; i++) {
    res = res && (keep[0] == keep[i]);
  }
  return res;
}
void set_to_blue() {
    for(int i=0; i<NUM_LEDS; i++){
      leds[i] = CHSV(140, 230, 255);
    }
        FastLED.show();
    Serial.println("SET TO BLUE");
}

void set_to_orange() {
      for(int i=0; i<NUM_LEDS; i++){
        leds[i] = CHSV(25, 230, 180);
      }
        FastLED.show();
    Serial.println("SET TO ORANGE");
}

void setup() { 
    FastLED.addLeds<NEOPIXEL, BLUE_PIN>(leds_blue, NUM_LEDS);  // GRB ordering is assumed
    FastLED.addLeds<NEOPIXEL, ORANGE_PIN>(leds_orange, NUM_LEDS);  // GRB ordering is assumed
    pinMode(myPin, INPUT);
     FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
    for (int i = 0; i < D; i++) {
      keep[i] = LOW;  
  }
}

void loop() {
  double f = (sin(time / 10.0)+ 1) / 2.0 * 255;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_blue[i] = CHSV(140, 230, f);
    leds_orange[i] = CHSV(35, 250, f);
  }
  FastLED.show();
  time++;
  keep[readhead] = digitalRead(myPin);
  readhead = (readhead + 1) % D;
  if (reduce_keep()) {
    set_to_orange();
  }
  else {
    set_to_blue();
  }
}
