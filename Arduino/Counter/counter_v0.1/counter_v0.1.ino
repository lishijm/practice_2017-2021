//通过1602LCD显示屏显示通过人次，不分辨进出方向，不分辨人是否停留
#include<Arduino.h>
#include<LiquidCrystal.h>
const int rs=3,en=4,d4=5,d5=6,d6=7,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//以下字库由二进制转为十六进制
uint8_t ren[8]={0x02,0x02,0x04,0x04,0x04,0x0A,0x0A,0x11,};//“人”字库
uint8_t ci[8]={0X04,0X17,0X15,0X02,0X0A,0X15,0X15,0X15,};//“次”字库
int nop=0;               //人次的变量
void setup(){
  pinMode(2,INPUT); 
  lcd.begin(16,2);      //红外开关数据端口
  lcd.createChar(0,ren);//创建字符
  lcd.createChar(1,ci); //创建字符
  lcd.setCursor(14,1);
  lcd.write((byte)0);
  lcd.write((byte)1);
}
void loop(){
  if(digitalRead(2)==0){
    nop++;
    delay(500);
  }
  lcd.setCursor(0,0);
  lcd.print(nop);
}
