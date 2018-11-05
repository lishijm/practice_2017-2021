int flag01=0,flag02=0;
int t=10;
float speedr=132,speedl=160;
void goAhead(float speedl,float speedr) {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(3,speedr);        //右轮速度参数
  analogWrite(5,speedl);        //左轮速度参数
}
void turnLeft(float speedl,float speedr) {
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(3,speedr);
  analogWrite(5,speedl);
}
void turnRight(float speedl,float speedr) {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  analogWrite(3,speedr);
  analogWrite(5,speedl);
}
void setup()
{
  pinMode(6, INPUT);
  pinMode(2, INPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop()
{
  if (digitalRead(6)) {
    turnLeft(speedl,speedr);
    delay(t);
    flag01++;

  }
  if (digitalRead(2)) {
    turnRight(speedl,speedr);
    delay(t);
    flag02++;

  }
    if (digitalRead(6)) {
    turnLeft(speedl,speedr);
    delay(t);
    flag01++;

  }
  if (digitalRead(2)) {
    turnRight(speedl,speedr);
    delay(t);
    flag02++;

  }
  if(flag01+flag02>=3){
    speedl-2.424;
    speedr-2;
    flag01=0;
    flag02=0;
  }
  goAhead(speedl,speedr);

}
