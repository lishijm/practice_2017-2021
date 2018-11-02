void goAhead() {
  pinMode(A0, OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3,HIGH);
  analogWrite(3,132);
  analogWrite(5,160);
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
  analogWrite(3,132);
  analogWrite(5,160);
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
  analogWrite(3,132);
  analogWrite(5,160);
}
void setup()
{
  pinMode(6, INPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (digitalRead(6)) {
    turnLeft();
    delay(1);

  }
  if (digitalRead(2)) {
    turnRight();
    delay(1);

  }
  goAhead();

}
