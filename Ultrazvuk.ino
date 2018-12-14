// Arduino UNO, LCD Shield HD44780, Ultrasonic module HC-SR04

#include <LiquidCrystal.h>

#define ECHOPIN 2 // Echo pin z HC-SC04 na pin 2 
#define TRIGPIN 3 // Trig pin z HC-SC04 na pin 3

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() { 
  lcd.begin(16, 2);
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
  }

void loop() { 
  // Vyšle impuls do modulu HC-SR04 
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  
  // Spočítá vzdálenost 
  float distance = pulseIn(ECHOPIN, HIGH); 
  distance = distance * 0.017315f; 

  lcd.setCursor(0,0);
  lcd.print("vzdalenost [cm]:");
  lcd.setCursor(0,1);
  lcd.print(distance);

  if (distance < 20){
    lcd.setCursor(8,1);
    lcd.print("!POZOR!");
    delay(500);
  }
  else{
    delay(500);
  }
  lcd.setCursor(8,1);
  lcd.print("       ");
  delay(500); 
}
