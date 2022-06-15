#include "UI.h"

Adafruit_HX8357 tft1 = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Size of the color selection boxes and the paintbrush size
#define BOXSIZE 40
#define PENRADIUS 3
int oldcolor, currentcolor;

hw_timer_t * timer0 = NULL;
portMUX_TYPE timerMux0 = portMUX_INITIALIZER_UNLOCKED;


extern bool x = false;
int i = 0;

void IRAM_ATTR isr(){
    portENTER_CRITICAL_ISR(&timerMux0);
    interrupts();
    //Serial.println("Button 1 Interrupt");


   if(x == true){
     setupScreen2();
   }
    portEXIT_CRITICAL_ISR(&timerMux0);

    
}


void setup(void) {

  pinMode(33, INPUT);
  pinMode(15, INPUT);
  pinMode(32, OUTPUT);
  analogReadResolution(10);
  Serial.begin(9600);
  Serial.println(F("Touch Paint!"));

  
  tft1.begin();
  setupScreen1();
  
    //timer0 = timerBegin(0,80,1);
    //timerAttachInterrupt(timer0, &isr, true);
   // timerAlarmWrite(timer0, 1000000);
   // timerAlarmEnable(timer0);

  //attachInterrupt(digitalPinToInterrupt(15), isr, RISING);
  
}

void loop()
{
  
  //int x = analogRead(33);
  //int y = digitalRead(15);
  //Serial.print(x);
  //Serial.print("   ");
  //Serial.print(y);
  //Serial.print("\n");
  TSPoint p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft1.width());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft1.height());

    //Detects Button 1 Press
  if( ((p.x - 21)*(p.x - 21) + (p.y - 410)*(p.y - 410)) <= 400 ){
      Serial.print("\nButton1");
      x = false;
      
  }
    //Detects Button 2 Press
  else if( ((p.x - 160)*(p.x - 160) + (p.y - 410)*(p.y - 410)) <= 400 ){
      Serial.print("\nButton2");
      
      x = true;
      timer0 = timerBegin(0,80,1);
      if(timerReadSeconds(timer0) > 3 ){
        
        timerAttachInterrupt(timer0, &isr, true);
        timerAlarmWrite(timer0, 1000000,false);
        timerAlarmEnable(timer0);
        i++;
      }
    
      
  }
    //Detects Button 3 Press
  else if( ((p.x - 299)*(p.x - 299) + (p.y - 410)*(p.y - 410)) <= 400 ){
      Serial.print("\nButton3");
      x = false;
      
  }
  else{
    x = false;
  }


  
 
}


