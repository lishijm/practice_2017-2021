void goAhead() {
  pinMode(A0, OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3,HIGH);
  analogWrite(3,71);
  analogWrite(5,98);
}
void turnLeft() {
  pinMode(A0, OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1,HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3,HIGH);
  analogWrite(3,71);
  analogWrite(5,98);
}
void turnRight() {
  pinMode(A0, OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2,HIGH);
  pinMode(A3, OUTPUT);
  digitalWrite(A3,LOW);
  analogWrite(3,71);
  analogWrite(5,98);
}
void setup()
{
  pinMode(6, INPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (digitalRead(6)) {
    turnRight();
    delay(10);

  }
  if (digitalRead(2)) {
    turnLeft();
    delay(10);

  }
  goAhead();

}