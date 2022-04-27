#include <FastLED.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        9 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 300 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.

CRGB leds[NUMPIXELS];
int sensorValueInit = 200;
int myPin = 3;
bool stateValue = false;
int sensorValue = 0; 
bool INIT = true;

enum STATE { STANDBY, BLUE, ORANGE };
int state = STANDBY;

const int D = 2;
bool guard[D];

bool guard_not_done(void) {
  for (int i = 0; i < D; i++) if (!guard[i]) return true;
  return false;
}
void tick_change_signal(void) {
  for (int i = 0; i < D; i++)
    if (!guard[i]) {
      guard[i] = true;
      return;
    }
}
void reset_guard() {
  for (int i = 0; i < D; i++) guard[i] = false;
}

void set_to_blue() {
    for(int i=0; i<NUMPIXELS; i++){
      leds[i] = CHSV(140, 230, 255);
    }
      if (state != STATE::BLUE) {
        FastLED.show();
        state = STATE::BLUE;
      }
    Serial.println("SET TO BLUE");
}

void set_to_orange() {
  Serial.print("yo");
      for(int i=0; i<NUMPIXELS; i++){
        leds[i] = CHSV(40 , 200, 255);
      }
      if (state != STATE::ORANGE) {
        FastLED.show();
        state = STATE::ORANGE;
      }
    Serial.println("SET TO ORANGE");
}

bool need_to_go_blue(const int& x) {
  Serial.print(x);
  Serial.print(" | ");
  Serial.println(sensorValueInit - 2);
  return x >= (sensorValueInit - 2);
}

bool need_to_go_orange(const int& x) {
  return !need_to_go_blue(x);  
}

void setup() {
  pinMode(myPin, INPUT);
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUMPIXELS);
  Serial.begin(9600);
  reset_guard();
}

void loop() {
  if (millis() > 5000 && INIT){
    Serial.print("HIT: ");
    Serial.println(sensorValue);
    sensorValueInit = analogRead(myPin);
    INIT = false;
  }
   else if (INIT == true){ 
    sensorValue = analogRead(myPin);
    Serial.println(sensorValue);
    return; 
    }
  
    sensorValue = analogRead(myPin);
    Serial.print(state);
    Serial.print(": ");
    Serial.print(sensorValue);
    Serial.print(": ");
    Serial.println(sensorValueInit);
    if (need_to_go_blue(sensorValue)){
      set_to_blue();
      while (guard_not_done()) {
        if (need_to_go_orange(analogRead(myPin))){
          tick_change_signal();
        }
        else{
          reset_guard();
        }
      }
    }
    else if (need_to_go_orange(sensorValue)) {
      set_to_orange();
      Serial.println("!!!");
      while (guard_not_done()) {
        if (need_to_go_blue(analogRead(myPin))){
          tick_change_signal();
        }
        else
          reset_guard();
      }
    }
    reset_guard();
}
