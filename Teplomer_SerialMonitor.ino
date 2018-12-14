// Arduino UNO, LCD Shield HD44780, Senzor teploty a vlhkosti DHT11

#include "DHT.h"           // připojení knihovny DHT
#define pinDHT 5           // nastavení čísla pinu s připojeným DHT senzorem
#define typDHT11 DHT11

DHT cidloDHT(pinDHT, typDHT11); // inicializace DHT senzoru s nastaveným pinem a typem senzoru

void setup() {
  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600); 
  // zapnutí komunikace s teploměrem DHT
  cidloDHT.begin();
}

void loop() {
  // pomocí funkcí readTemperature a readHumidity načteme
  // do proměnných tep a vlh informace o teplotě a vlhkosti,
  // čtení trvá cca 250 ms
  float tep = cidloDHT.readTemperature();
  float vlh = cidloDHT.readHumidity();
  
    Serial.print("Teplota: "); 
    Serial.print(tep);
    Serial.print(" °C, ");
    Serial.print("vlhkost: "); 
    Serial.print(vlh);
    Serial.println(" %");
  
  delay(2000);
}
