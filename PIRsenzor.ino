// Arduino UNO
// PIR senzor
// reproduktor
// LCD Shield HD44780
// Senzor teploty a vlhkosti DHT22 (AM2302)

#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int vstup = 12;
int pohyb;
int repro = 2;
int led = 13;

void setup() {
  lcd.begin(16,2);
  pinMode(vstup, INPUT_PULLUP);
  pinMode(repro, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  pohyb = digitalRead(vstup);
  
  if(pohyb){
    digitalWrite(led, HIGH);
    tone(repro, 200);
    lcd.clear();
    lcd.print("POHYB!");
    delay(100);
  }
  else{
    digitalWrite(led, LOW);
    noTone(repro);
    lcd.clear();
    lcd.print("klid");
    delay(100);
  }
}
