#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        1 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 300 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

int myPin = 3;
bool stateValue = false;
int prevState;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
}

void loop() {
  // put your main code here, to run repeatedly:
    float sensorValue = analogRead(myPin);
    Serial.println(sensorValue);
    if (sensorValue > 140){
      
  
  if (prevState == 141){
    stateValue = false;
  }
  prevState = 140;
  if (stateValue == false){
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 100, 0));
    
       // Send the updated pixel colors to the hardware.
    stateValue = true;
  }
    pixels.show();
  }
    }
  else {
  if (prevState == 140){
    stateValue = false;
  }
  prevState = 141;
  if (stateValue == false){
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    
       // Send the updated pixel colors to the hardware.
    stateValue = true;
  }
    pixels.show();
  }
  }
  
}
