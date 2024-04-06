//  file: lumini_metro_example.ino
//  
//  Tutorials available from SparkFun, per:
//    https://learn.sparkfun.com/tutorials/lumini-8x8-matrix-hookup-guide/all
//    and
//    https://github.com/sparkfun/Lumini_8x8/tree/master/Firmware


#include <FastLED.h>

// How many leds in your chain? Change the value of NUM_BOARDS depending on your setup
#define NUM_BOARDS 1
#define NUM_LEDS 64 * NUM_BOARDS //64 LED's per board

// Pins on the Adafruit Metro Mo Express
#define DATA_PIN 7   // connected to LuMini DI, data  in
#define CLOCK_PIN 6  // connected to LuMini CI, clock in 

// Define the array of leds
CRGB matrix[NUM_LEDS];
int delayTimeLength = 10;


void setup() {
  Serial.begin(115200);
  Serial.println("resetting");
  LEDS.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(matrix, NUM_LEDS);
  LEDS.setBrightness(0);
}


void setAllColour(int changeRed=0, int changeGreen=0, int changeBlue=0) {
  for (int i = 0; i < NUM_LEDS; i++) {
    matrix[i].setRGB(changeRed, changeGreen, changeBlue); // red
  }
  FastLED.show();
}

void setRedBlueYellow() {
  int readInputRed = analogRead(A3);
  int readInputBlue = analogRead(A4);
  int readInputYellow = analogRead(A5);

  int analogThreshold  = 100;

  bool isSelectedRed = false;
  bool isSelectedBlue = false;
  bool isSelectedYellow = false;

  //

  if (readInputRed < analogThreshold) {
    isSelectedRed = true;
  }
  if (readInputBlue < analogThreshold) {
    isSelectedBlue = true;
  }
  if (readInputYellow < analogThreshold) {
    isSelectedYellow = true;
  }

  //

  if (isSelectedRed && isSelectedBlue && isSelectedYellow) {
    // white
    setAllColour(255,255,255);
  }
  else if (isSelectedRed && isSelectedBlue) {
    // purple
    setAllColour(105,0,255);
  }
  else if (isSelectedRed && isSelectedYellow) {
    // orange
    setAllColour(255,70,0);
  }
  else if (isSelectedBlue && isSelectedYellow) {
    // green
    setAllColour(0,255,0);
  }
  else if (isSelectedRed) {
    // red
    setAllColour(255,0,0);
  }
  else if (isSelectedBlue){
    // blue
    setAllColour(0,0,255);
  }
  else if (isSelectedYellow){
    // yellow
    setAllColour(255,255,0);
  }
  else {
    // black
    setAllColour(0,0,0);
  }
}


void setAllBrightness() {
  int readBrightnessPotentiometer = analogRead(A0);
  int changeBrightness = 0;
  // brightness needs to be an integer between 0 - 100
  
  if (readBrightnessPotentiometer < 200) {
    changeBrightness = 100;
  }
  else if (readBrightnessPotentiometer < 400) {
    changeBrightness = 80;
  }
  else if (readBrightnessPotentiometer < 600) {
    changeBrightness = 60;
  }
  else if (readBrightnessPotentiometer < 800) {
    changeBrightness = 40;
  }
  else if (readBrightnessPotentiometer < 1000) {
    changeBrightness = 20;
  }
  else {
    changeBrightness = 0;
  }
  LEDS.setBrightness(changeBrightness);
  FastLED.show();
}


void loop() {
  setRedBlueYellow();
  setAllBrightness();
  delay(delayTimeLength);
}
