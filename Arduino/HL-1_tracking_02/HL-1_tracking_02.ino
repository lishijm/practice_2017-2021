#include<Arduino.h>

void goAhead() {
  digitalWrite(A0,HIGH);  
  digitalWrite(A1,LOW);  
  digitalWrite(A2,LOW);  
  digitalWrite(A3,HIGH);
  analogWrite(3,132);
  analogWrite(5,160);
}
void turnLeft() {
  digitalWrite(A0,LOW);  
  digitalWrite(A1,HIGH);  
  digitalWrite(A2,LOW);  
  digitalWrite(A3,HIGH);
  analogWrite(3,132);
  analogWrite(5,160);
}
void turnRight() {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(3,132);
  analogWrite(5,160);
}
void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
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
