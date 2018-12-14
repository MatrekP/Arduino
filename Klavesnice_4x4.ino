// Membránová klávesnice 4x4

// připojení knihovny
#include <Keypad.h>

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
byte pinyRadku[radky] = {9, 8, 7, 6}; //čísla pinů s řadkem 1 2 3 4
byte pinySloupcu[sloupce] = {5, 4, 3, 2}; //čísla pinu se sloupcem 1 2 3 4

// vytvoření instance klavesnice z knihovny Keypad
Keypad klavesnice = Keypad( makeKeymap(keys), pinyRadku, pinySloupcu, radky, sloupce); 

void setup() {
  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600);
}
  
void loop() {
  // načtení hodnoty stisknuté klávesy do proměnné
  char klavesa = klavesnice.getKey();
  // kontrola obsahu proměnné se stisknutou klávesou
  // pokud bylo cokoli stisknuto, vytiskneme klávesu
  // po Sériové lince
  if (klavesa){
    Serial.print("Stisknuta klavesa: ");
    Serial.println(klavesa);
  }
}
