#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Wire.h>
#include <DS1307.h>

// vytvoří objekt lcd a nastaví jeho adresu
// 0x27 a 20 zanků na 4 řádcích
LiquidCrystal lcd(8,9,4,5,6,7);
// vytvoří pole čísel do kterých se bude ukládat čas
int rtc[7];

void setup()
{
  RTC.stop(); // zastaví čas

  RTC.set(DS1307_SEC,1); //nastaví sekundy

  RTC.set(DS1307_MIN,57); // nastaví minuty

  RTC.set(DS1307_HR,17); // nastaví hodiny

  RTC.set(DS1307_DOW,2); // nastaví den v týdnu

  RTC.set(DS1307_DATE,18); // nastaví den v měsíci

  RTC.set(DS1307_MTH,1); // nastaví měsíc

  RTC.set(DS1307_YR,10); // nastaví rok

  RTC.start(); // spustí čas
  
lcd.begin(16,2);
lcd.setCursor(0,0); // nastaví kurzor na pozici
lcd.print(„Aktualni cas:“); // vypíše text
}
void loop()
{
//// zapíše data z modulu do pole čísel rtc
//RTC.get(rtc,true);
//// připraví pole znaků pro čas
//char cas[9];
//// zapíše do pole znaků cas hodnoty z rtc
//sprintf(cas, „%02d:%02d:%02d“, rtc[2],rtc[1],rtc[0]);
//lcd.setCursor(0,1); // nastaví kurzor na pozici
//lcd.print(cas); // vypíše cas na displej
//
////připraví pole znaků pro datum
//char dat[11];
////zapíše do pole znaků dat hodnoty z rtc
//sprintf(dat, „%02d.%02d.%4d“ ,rtc[4],rtc[5],rtc[6]);
//lcd.setCursor(5,0); //nastaví kurzor
//lcd.print(„Dnesni datum:“); //vypíše text
//lcd.setCursor(5,1); //nastaví kurzor
//lcd.print(dat); //vypíše datum
//
//delay(1000); //počká jednu vteřinu
}
