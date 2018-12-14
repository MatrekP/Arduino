// Akustický bzučák

// proměnná pro nastavení propojovacího pinu
int bzucak = 8;

void setup() {
}

void loop() {
  tone(bzucak, 200);
  delay(1000);
  noTone(bzucak);
  delay(2000);
}
