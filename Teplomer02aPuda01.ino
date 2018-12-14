// Arduino UNO, LCD Shield HD44780, Senzor teploty a vlhkosti DHT22 (AM2302), Senzor pudni vlhkosti YL69 a YL38,
// Senzor osvetleni, Hodinovy dislpej TM1637

#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 10   //teplota a vlhkost
#define DHTTYPE DHT22

#define analogPin A1  //pudni sonda
#define digitalPin 12

#define osvetleniPin A3 //svetelny senzor

LiquidCrystal lcd(8,9,4,5,6,7);
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  lcd.begin(16,2);
  dht.begin();
  pinMode(13, OUTPUT);
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
  pinMode(osvetleniPin, INPUT);
}

void loop(){
  dht.read(10);
  float teplota = dht.readTemperature();
  float vlhkost = dht.readHumidity();

  int analog = analogRead(analogPin);
  bool digit = digitalRead(digitalPin);

  int osvetleni = analogRead(osvetleniPin);
  
  lcd.clear();
  lcd.print(teplota,1);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C   ");
  lcd.print(vlhkost,1);
  lcd.print(" %");
  
  lcd.setCursor(0,1);
  lcd.print("p ");
  lcd.print(analog);
  lcd.print(" ");
  lcd.print(digit);

  lcd.print("  s ");
  lcd.print(osvetleni);
  
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
