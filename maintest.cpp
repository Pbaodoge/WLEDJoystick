/**Controlling WLED with a Joystick and colors
 * Used FastLED library: https://github.com/FastLED/FastLED
 * Made by Pbaodoge(Siesta)
 * Version: v1.5
 * WLED matrix code (well it took me 2 fucking days to build it)
*/

#include <Arduino.h>
#include <FastLED.h>

#define LEDPIN 6
#define NUMLEDS 300
#define button 7
#define pot A0

int z = 0;
int counter = 0;
char ledmode;
char brightness;
int read = 0;
int bstate = 0;
int NPXCTRL = 0;
CRGB MAINSTRIP[NUMLEDS];
    class utility {
      public:

       void effect1(){
         for(int z = 0; z <= NUMLEDS; z++){                 
           MAINSTRIP[z] = CRGB::Red;
           FastLED.show();
         }
         FastLED.clear();
         for(int z = NUMLEDS; z >= 0; z--){ 
            MAINSTRIP[z] = CRGB::Blue;
            FastLED.show();
        }       
         FastLED.clear(); 
    }



    void effect2(){
      for(int z = 0; z <= NUMLEDS; z++){ bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
    }
           MAINSTRIP[z] = CRGB::Red;
           FastLED.show();
           MAINSTRIP[z] = CRGB::Black;

         }

         FastLED.clear();
         for(int z = NUMLEDS - 1; z >= 0; z--){ bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
    }
              MAINSTRIP[z] = CRGB::Red;
              FastLED.show();
              MAINSTRIP[z] = CRGB::Black;
           
         }

         FastLED.clear();
    }





    void effect3(){
         for(int timer = 500; timer >= 20; timer-= 50){ bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
    }
           fill_solid(MAINSTRIP, NUMLEDS, CRGB::Cyan);
           FastLED.show();
           delay(timer);
           fill_solid(MAINSTRIP, NUMLEDS, CRGB::WhiteSmoke);
           FastLED.show();
           delay(timer);
           
         }
         FastLED.clear();
    }




    void effect4(){ 
      for(int efe4 = 0; efe4 <= 2; efe4++){
            for(int z = NUMLEDS; z >= 0; z--){ bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
    }
               FastLED.clear();
                  MAINSTRIP[z] = CRGB::Red;
                  MAINSTRIP[z-1] = CRGB::Red;
                  MAINSTRIP[z-2] = CRGB::Red;
                  MAINSTRIP[z-3] = CRGB::Red;
                  MAINSTRIP[z-4] = CRGB::Red;
                  MAINSTRIP[z-5] = CRGB::Red;
                    FastLED.show();
                    Serial.println(z);
      }
    }
    FastLED.clear();

      for(int efe4 = 0; efe4 <= 2; efe4++){
            for(int z = 0; z <= NUMLEDS; z++){bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
    }
               FastLED.clear();
                  MAINSTRIP[z] = CRGB::Violet;
                  MAINSTRIP[z+1] = CRGB::Violet;
                  MAINSTRIP[z+2] = CRGB::Violet;
                  MAINSTRIP[z+3] = CRGB::Violet;
                  MAINSTRIP[z+4] = CRGB::Violet;
                  MAINSTRIP[z+5] = CRGB::Violet;
                    FastLED.show();
                    Serial.println(z);
      }
    }
    FastLED.clear();
    
  }

  void mixtape(){ bstate = digitalRead(button); 
          if (bstate == LOW) { 
           counter = (counter + 1) % 11; return;
              while (bstate == LOW) bstate = digitalRead(button);
          }
      FastLED.clear();
         for(z = 0; z <= NUMLEDS; z++){
            MAINSTRIP[z] = CRGB(255, 200, 255);
            FastLED.show();

      }
      FastLED.clear();
      for(z = NUMLEDS; z >= 0; z--){
            MAINSTRIP[z] = CRGB::Violet;
            FastLED.show();

      }

      FastLED.clear();
      for(z = 0; z <= NUMLEDS; z++){
            MAINSTRIP[z] = CRGB::Tomato;
            FastLED.show();

      }
      FastLED.clear();
      for(z = NUMLEDS; z >= 0; z--){
            MAINSTRIP[z] = CRGB::Tomato;
            FastLED.show();

      }
      FastLED.clear();

    for(int count = 0; count <= 3; count++) {
      for(z = 0; z <= NUMLEDS; z += 2){
            MAINSTRIP[z] = CRGB(0, 200, 255);
            FastLED.show();

      }
      for(z = NUMLEDS; z >= 0; z -= 2){
            MAINSTRIP[z] = CRGB::Blue;
            FastLED.show();

      }
      FastLED.clear();

      for(z = 0; z <= NUMLEDS - 150; z += 2){
            MAINSTRIP[z] = CRGB::Red;
            FastLED.show();

      }
      FastLED.clear();
      for(z = NUMLEDS - 150; z >= 0; z -= 2){
            MAINSTRIP[z] = CRGB::Green;
            FastLED.show();

      }
      FastLED.clear();

      for(z = NUMLEDS - 150; z <= NUMLEDS; z += 2){
            MAINSTRIP[z] = CRGB::Brown;
            FastLED.show();

      }
      FastLED.clear();
      for(z = NUMLEDS; z >= NUMLEDS - 150; z -= 2){
            MAINSTRIP[z] = CRGB::Red;
            FastLED.show();

      }
      FastLED.clear();

    }

 }

};




    void setup() {
    Serial.begin(9600);
    FastLED.addLeds<WS2812B, LEDPIN, GRB> (MAINSTRIP, NUMLEDS);
    FastLED.clear();
    FastLED.show();
    pinMode(button, INPUT_PULLUP);
}


void loop(){
    utility utilcontrol;
    bstate = digitalRead(button);
    int read = analogRead(pot);
    int val = map(read, 0, 1024, 20, 255);
    if (bstate == LOW)
    {
        counter = (counter + 1) % 11;
        Serial.println(counter);
        while (bstate == LOW)
            bstate = digitalRead(button);
    }
    
    switch (counter){
        
            case 0:
                MAINSTRIP[1] = CRGB::Cyan;
                FastLED.show();
                break;
            case 1:
                fill_solid(MAINSTRIP, NUMLEDS, CRGB::Green);
                FastLED.show();
                break;
            case 2:
                fill_solid(MAINSTRIP, NUMLEDS, CRGB::Cyan);
                FastLED.show();
                break;
            case 3:
                fill_solid(MAINSTRIP, NUMLEDS, CRGB::Black);
                FastLED.show();
                break;
            case 4:
                fill_solid(MAINSTRIP, NUMLEDS, CRGB::White);
                FastLED.show();
                break;
            case 5:
                utilcontrol.effect1();
                break;
            case 6:
                utilcontrol.effect2();
                break;
            case 7:
                utilcontrol.effect3();
                break;
            case 8:
                utilcontrol.effect4();
                break;
            case 10:
                utilcontrol.mixtape();
                break;

            default:
                break;
       }
    FastLED.setBrightness(val);
    FastLED.show();

}
