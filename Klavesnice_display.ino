// Arduino MEGA, LCD Shield HD44780, Membránová klávesnice 4x4

// připojení knihovny
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(8,9,4,5,6,7);

// vytvoření proměnných údávajících
// počet řádků a sloupců klávesnice
const byte radky = 4;
const byte sloupce = 4;
// vytvoření pole s rozmístěním kláves
char keys[radky][sloupce] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// nastavení čísel pinů pro spojení s klávesnicí
byte pinyRadku[radky] = {23, 25, 27, 29}; //čísla pinů s řadkem 1 2 3 4
byte pinySloupcu[sloupce] = {31, 33, 35, 37}; //čísla pinu se sloupcem 1 2 3 4

// vytvoření instance klavesnice z knihovny Keypad
Keypad klavesnice = Keypad( makeKeymap(keys), pinyRadku, pinySloupcu, radky, sloupce); 

void setup() {
  lcd.begin(16,2);
}
  
void loop() {
  // načtení hodnoty stisknuté klávesy do proměnné
  char klavesa = klavesnice.getKey();
  // kontrola obsahu proměnné se stisknutou klávesou
  // pokud bylo cokoli stisknuto, vytiskneme klávesu
  if (klavesa){
    lcd.setCursor(0,0);
    lcd.print("Klavesa: ");
    lcd.print(klavesa);
    tone(50, 500);
    delay(500);
    noTone(50);
  }
}
