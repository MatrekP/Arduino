void setup() {
pinMode(13, OUTPUT);
pinMode(2, INPUT_PULLUP);
}

void loop() {
int cteni = digitalRead(2);

if(cteni){
  digitalWrite(13, HIGH);
  delay(10000);
  }
  else{
  digitalWrite(13, LOW);
  }
}
