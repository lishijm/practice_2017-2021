//只实现恒温加热功能
#include<Arduino.h>
#include<OneWire.h>
#include<DallasTemperature.h>
//#include<LiquidCrystal.h>

#define sensora 2
#define sensorb 3
const int repin=8;
int tmpc;  //设定的温度变量
int tmp1;  //一号传感器的温度
//int tmp2;  //二号传感器的温度
int flag=0; //判断是非设定温度
OneWire onewire(sensora);
DallasTemperature sensors(&onewire);

void setup(){
  sensors.begin();
  pinMode(repin,OUTPUT);
  Serial.begin(9600); //串口监视波率
}
void loop(){
  //串口数据读取
  if(flag==0){
    tmpc=Serial.parseInt();
  }
  if(tmpc>0){
    flag=1;
  }
  
  sensors.requestTemperatures();
  tmp1=sensors.getTempCByIndex(0);
  Serial.print(tmp1);
  Serial.print("℃\n");
  //tmpc后的数值为消抖所设定的温度阈值，其准确值待明日测试时考证
  if(tmp1<=tmpc-2){
    digitalWrite(repin,HIGH);
  }
  if(tmp1>tmpc+1){
    digitalWrite(repin,LOW);
  }

  delay(1000);
}
