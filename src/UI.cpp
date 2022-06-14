#include "masterLib.h"

Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

void bottomCirclesandText(Adafruit_HX8357 tft){
    tft.drawCircle(21,410,20,0x0000);
    tft.drawCircle(160,410,20,0x0000);
    tft.drawCircle(299,410,20,0x0000);

    tft.setCursor(21 - 5,410 - 8);
    tft.setTextColor(0x0000);
    tft.setTextSize(3.5);
    tft.println("1");

    tft.setCursor(160 - 5,410 - 8);
    tft.setTextSize(3.5);
    tft.println("2");

    tft.setCursor(299 - 5,410 - 8);
    tft.setTextSize(3.5);
    tft.println("3");

    tft.setCursor(2, 410 + 30);
    tft.setTextSize(1.5);
    tft.println("Scroll Up");
    
    tft.setCursor(160-40, 410 + 30);
    tft.println("Hold to Change");
    tft.setCursor(160-10, 410 + 45);
    tft.println("Mode");

    tft.setCursor(250, 410 + 30);
    tft.setTextSize(1.5);
    tft.println("Scroll Down");


    tft.setCursor(160-40, 380 );
    tft.println("Ping Selected");
}

void topLabelScreen1(Adafruit_HX8357 tft){
    tft.setCursor(10,10);
    tft.setTextSize(2.5);
    tft.setTextColor(0x0000);
    tft.println("Hub Status Mode");

    tft.setCursor(10,35);
    tft.setTextSize(1.5);
    tft.println("MAC Address       Device ID                RSSI");
}

void topLabelScreen2(Adafruit_HX8357 tft){
    tft.setCursor(10,10);
    tft.setTextSize(2.5);
    tft.setTextColor(0x0000);
    tft.println("Hub Receive Mode");

    tft.setCursor(10,35);
    tft.setTextSize(1.5);
    tft.println("MAC Address       Device ID                RSSI");
}

void topLabelScreen3(Adafruit_HX8357 tft){
    tft.setCursor(10,10);
    tft.setTextSize(2.5);
    tft.setTextColor(0x0000);
    tft.println("Badge Receive Mode");

    tft.setCursor(10,35);
    tft.setTextSize(1.5);
    tft.println("MAC Address       Device ID                RSSI");
}

void topLabelScreen4(Adafruit_HX8357 tft){
    tft.setCursor(10,10);
    tft.setTextSize(2.5);
    tft.setTextColor(0x0000);
    tft.println("Badge Emulate Mode");
}

void setupScreen1(){
    tft.begin();
    tft.fillScreen(0xFFFF);
    bottomCirclesandText(tft);
    topLabelScreen1(tft);
}

void setupScreen2(){
    tft.begin();
    tft.fillScreen(0xFFFF);
    bottomCirclesandText(tft);
    topLabelScreen2(tft);
}

void setupScreen3(){
    tft.begin();
    tft.fillScreen(0xFFFF);
    bottomCirclesandText(tft);
    topLabelScreen3(tft);
}

void setupScreen4(){
    tft.begin();
    tft.fillScreen(0xFFFF);
    bottomCirclesandText(tft);
    topLabelScreen4(tft);
}







