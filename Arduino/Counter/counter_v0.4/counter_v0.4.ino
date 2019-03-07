//相较于0.1版本加入内容滚动,内容滚动一定时间后可重新显示通过人次
#include<Arduino.h>
#include<LiquidCrystal.h>
const int rs=3,en=4,d4=5,d5=6,d6=7,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//以下字库由二进制转为十六进制
uint8_t ren[8]={0x02,0x02,0x04,0x04,0x04,0x0A,0x0A,0x11,};//“人”字库
uint8_t ci[8]={0X04,0X17,0X15,0X02,0X0A,0X15,0X15,0X15,};//“次”字库
int nop=0;               //人次的变量
int sx=0;
int sy=0;
int flag=0;

void setup(){
  pinMode(13,OUTPUT);
  pinMode(2,INPUT); 
  
  lcd.begin(16,2);      //红外开关数据端口
  lcd.createChar(0,ren);//创建字符
  lcd.createChar(1,ci); //创建字符
}
void scnop(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(nop);
    lcd.setCursor(14,1);
    lcd.write((byte)0);
    lcd.write((byte)1);
}
void loop(){

  if(digitalRead(2)==0){
    nop++;
    digitalWrite(13,HIGH);
    scnop();
  }
  else{
    if(flag<=19){
      if(sx>9){
        sx=0;
        if(sy==1){
          sy=0;
        }
        else{
          sy=1;
        }        
      }
      lcd.clear();
      lcd.setCursor(sx,sy);
      lcd.print("GROUP 3");
      sx++;
    }
    flag++;
    if(20<=flag&&flag<=40){
      scnop();
    }
    if(flag==41){
      flag=0;
    }
  }
  
  delay(700);
}
