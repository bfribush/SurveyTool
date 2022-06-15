#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include <Wire.h>
//#include "FreeRTOSConfig.h"
//#include "freertos/FreeRTOS.h"
//#include <avr/io.h>


#define TFT_CS 4
#define TFT_DC 13
#define TFT_RST 8 

#include <stdint.h>
#include "TouchScreen.h"


#define YP A0 // must be an analog pin, use "An" notation!
#define XM A1  // must be an analog pin, use "An" notation!
#define YM 27   // can be a digital pin
#define XP 12   // can be a digital pin

#define TS_MINX 200
#define TS_MINY 80
#define TS_MAXX 900
#define TS_MAXY 940

#define MINPRESSURE 10
#define MAXPRESSURE 10000

//extern Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
