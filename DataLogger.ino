// Arduino UNO, Data Logger Shield DS1307
// Funkce data a času s využitím DS1307 RTC připojeního I2C a Wire (Data Logger Shield)
 
// vložíme si potřebné knihovny
#include <Wire.h>
#include <RTClib.h>
 
//vytvoříme si objekt hodin
RTC_DS1307 RTC;
 
void setup () {
    Serial.begin(57600); //nastavíme rychlost komunikace COM portu
    Wire.begin(); //spustíme
    RTC.begin();  //spustíme
 
//při nahrávání nastavit čas, POZOR!!
 //RTC.adjust(DateTime(__DATE__, __TIME__));
 

 
}
 
void loop () {
  //zeptáme se na aktuální čas (přiřadíme do proměnné "now", kterou máme typu DateTime)
    DateTime now = RTC.now();
   
    Serial.print(now.year(), DEC); //now.year -> vrací aktuální rok.
    Serial.print('/');
    Serial.print(now.month(), DEC); //now.month -> vrací aktuální měsíc.
    Serial.print('/');
    Serial.print(now.day(), DEC); //now.day -> vrací aktuální den a analogicky dále...
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
   
    delay(3000); //počkáme 3 sec (nebo jak je libo)
}
