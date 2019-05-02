//只实现恒温加热
#include<Arduino.h>
#include<OneWire.h>
#include<DallasTemperature.h>
#define BUS 2
OneWire onewire(BUS);
DallasTemperature sensors(&onewire);
void setup() {
  //6.8k (DS18b20数字输出引脚需要接4.7k-10k上拉电阻)
  //针脚定义 面朝印字面，左为GND,右为VCC,中间为数字输出引脚（接4.7-10k上拉电阻）
  Serial.begin(9600);
  sensors.begin();
}
 
void loop() {
  // put your main code here, to run repeatedly:
   sensors.requestTemperatures();
   Serial.print(sensors.getTempCByIndex(0));
   Serial.print("℃\n");
   delay(1000);
}

/*const int relayPin =7; //the "s" of relay module attach to

void setup()
{
  pinMode(relayPin, OUTPUT); //initialize relay as an output
}

void loop()
{
  digitalWrite(relayPin, HIGH); //Close the relay
  delay(1000); //wait for 1 second
  digitalWrite(relayPin, LOW); //disconnect the relay 
  delay(1000); //wait for 1 second
}
*/
