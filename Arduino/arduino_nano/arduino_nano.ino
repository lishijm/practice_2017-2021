void setup() {
  pinMode(13, OUTPUT);
  pinMode(4,INPUT);
}
void loop() {
  if(digitalRead(4)==1){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}
