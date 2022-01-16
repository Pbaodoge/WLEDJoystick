/**Controlling WLED with a Joystick and colors
 * Used FastLED library: https://github.com/FastLED/FastLED
 * Made by Pbaodoge(Siesta)
 * Version: v1.0
*/
#include <Arduino.h>
#include <FastLED.h>
#define LEDPIN 5
#define NUMLEDS 300
#define CTRL A5
#define button 7
int z = 0;
int counter = 0;
CRGB MAINSTRIP[NUMLEDS];

      
    void changemode(){
      switch(counter){
        case 0:
         for(int r = 0; r < z; r++){
              MAINSTRIP[r] = CRGB::White;

            }
            FastLED.show();
            break;

            case 1:
            for(int r = 0; r < z; r++){
              MAINSTRIP[r] = CRGB::Green;

            }
            FastLED.show();
            break;

            case 2:
            for(int r = 0; r < z; r++){
              MAINSTRIP[r] = CRGB::Red;

            }
            FastLED.show();
            break;

            case 3:
            for(int r = 0; r < z; r++){
              MAINSTRIP[r] = CRGB::BlueViolet;

            }
            FastLED.show();
            break;

            case 4:
            for(int r = 0; r < z; r++){
              MAINSTRIP[r] = CRGB::Pink;

            }
            FastLED.show();
            break;
            
            default:
              counter = 0;
              break;

        }
    }
    void setup(){
        Serial.begin(9600);
        FastLED.addLeds<WS2812B, LEDPIN, GRB>(MAINSTRIP, NUMLEDS);
        pinMode(button, INPUT_PULLUP);

    }

    void loop(){
     int read = analogRead(CTRL);
     int NPXCTRL = map(read, 0, 1023, 0, 100);
     int bstate = digitalRead(button);

      if(bstate == LOW){
        counter += 1;
        changemode();
    }
     if(NPXCTRL > 70){
       changemode();
       z++;

    } else if(NPXCTRL < 30){
        MAINSTRIP[z] = CRGB::Black;
        FastLED.show();
        z--;

    } 
    else{
     changemode();

    }

    Serial.println(z);
    delay(1);

}