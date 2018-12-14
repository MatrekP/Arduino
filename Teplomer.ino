// Arduino UNO, LCD Shield HD44780, Senzor teploty a vlhkosti DHT11

#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 10
#define DHTTYPE DHT11

LiquidCrystal lcd(8,9,4,5,6,7);
DHT dht(DHTPIN, DHTTYPE);

void setup(){
lcd.begin(16,2);
dht.begin();
pinMode(13, OUTPUT);
}

void loop(){
dht.read(10);
int teplota = dht.readTemperature();
int vlhkost = dht.readHumidity();

lcd.setCursor(0,0);
lcd.print("teplota: ");
lcd.print(teplota);
lcd.print(" ");
lcd.print((char)223);
lcd.print("C");

lcd.setCursor(0,1);
lcd.print("vlhkost: ");
lcd.print(vlhkost);
lcd.print(" %");

digitalWrite(13, HIGH);
delay(500);
digitalWrite(13, LOW);
delay(500);
}
