#include <Arduino.h>
#include <FastLED.h>

#define LEDPIN 5 //Signal Pin
const int NUMLEDS = 300; //Number of LEDs
#define VAL 255 //max color value

CRGB MAINLED[NUMLEDS]; 

     void setup() {
       Serial.begin(9600);
       FastLED.addLeds<WS2812, LEDPIN, GRB>(MAINLED, NUMLEDS);

    }
    //control the speed of LEDs changing process from 1ms - 50ms
    int speedctrl(){
      int read = analogRead(A5);
      int speed = map(read, 0, 1023, 1, 100);

      return speed;
    }
    void loop() {

     for(int z = 0; z < NUMLEDS; z++){
          Serial.println(z);
          MAINLED[z] = CRGB(VAL, 0, 0);  //red mode
          FastLED.show();
          delay(speedctrl());

     }
     Serial.println("--------------------------------------------Reverse!----------------------------------------");
     for(int z = NUMLEDS - 1; z >= 0; z--){
       Serial.println(z);
       MAINLED[z] = CRGB::Black;
       FastLED.show();
       delay(speedctrl());

     }
     for(int z = 0; z < NUMLEDS; z++){
       Serial.println(z);
       MAINLED[z] = CRGB(0, VAL, 0);  //green mode
       FastLED.show();
       delay(speedctrl());

     }
     Serial.println("--------------------------------------------Reverse!----------------------------------------");
     for(int z = NUMLEDS - 1; z >= 0; z--){
       Serial.println(z);
       MAINLED[z] = CRGB::Black;
       FastLED.show();
       delay(speedctrl());

     }
     for(int z = 0; z < NUMLEDS; z++){
       Serial.println(z);
       MAINLED[z] = CRGB(0, 0, VAL);  //blue mode
       FastLED.show();
       delay(speedctrl());

     }
     Serial.println("--------------------------------------------Reverse!----------------------------------------");
     for(int z = NUMLEDS - 1; z >= 0; z--){
       Serial.println(z);
       MAINLED[z] = CRGB::Black;
       FastLED.show();
       delay(speedctrl());

     }
     for(int z = 0; z < NUMLEDS; z++){
       Serial.println(z);
       MAINLED[z] = CRGB(200, 255, 255); //white mode
       FastLED.show();
       delay(speedctrl());
       
     }
     Serial.println("--------------------------------------------Reverse!----------------------------------------");
     for(int z = NUMLEDS - 1; z >= 0; z--){
       Serial.println(z);
       MAINLED[z] = CRGB::Black;
       FastLED.show();
       delay(speedctrl());

     }
     for(int z = 0; z < NUMLEDS; z++){
       Serial.println(z);
       MAINLED[z] = CRGB(0, 255, 255); //cyan mode
       FastLED.show();
       delay(speedctrl());

     }
     Serial.println("--------------------------------------------Reverse!----------------------------------------");
     for(int z = NUMLEDS - 1; z >= 0; z--){
       Serial.println(z);
       MAINLED[z] = CRGB::Black;
       FastLED.show();
       delay(speedctrl());

     }

  }