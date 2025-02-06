
#include <FastLED.h>

#define NUM_LEDS 36
#define DATA_PIN 2
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];


void ColorRojo() {
  for (int i = 0; i < 10; i++) {
    leds[0]=CRGB::Red;
    leds[1]=CRGB::Red;
    leds[2]=CRGB::Red;
    leds[3]=CRGB::Red;
    leds[4]=CRGB::Red;
    leds[5]=CRGB::Red;
    leds[6]=CRGB::Red;
    leds[7]=CRGB::Red;
    leds[8]=CRGB::Red;
    leds[9]=CRGB::Red;
    leds[10]=CRGB::Red;
    leds[11]=CRGB::Red;
    FastLED.show();
    delay(3000);
    FastLED.clear();
    delay(1000);
  }
}

void setup() {
  delay(1000); 

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(80); // Ajusta el brillo según sea necesario

}

void loop() {
  
  for (int i = 0; i < 10; i++) {
    leds[0]=CRGB::Red;
    leds[1]=CRGB::Red;
    leds[2]=CRGB::Red;
    leds[3]=CRGB::Red;
    leds[4]=CRGB::Red;
    leds[5]=CRGB::Red;
    leds[6]=CRGB::Red;
    leds[7]=CRGB::Red;
    leds[8]=CRGB::Red;
    leds[9]=CRGB::Red;
    leds[10]=CRGB::Red;
    leds[11]=CRGB::Red;
    FastLED.show();
    delay(1000);
    FastLED.clear();
    delay(500);
  }
  
}
