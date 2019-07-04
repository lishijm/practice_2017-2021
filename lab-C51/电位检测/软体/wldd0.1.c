//基于AT89C52平台，借助ADC0809检测电位变化，使用共阳数码管显示，数值0~100
#include<reg52.h>

unsigned char code dispbitcode[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char dispbuf[4];
unsigned int i;
unsigned int j;
unsigned char getdata;
unsigned int temp;

unsigned char count;
unsigned char d;
sbit ST=P2^0;
sbit OE=P2^1;
sbit EOC=P2^2;
sbit CLK=P2^3;
sbit P34=P2^4;
sbit P35=P2^5;
sbit P36=P2^6;
sbit P30=P3^0;
sbit P31=P3^1;
sbit P32=P3^2;
sbit P33=P3^3;
sbit P17=P1^7;
void TimeInitial();
void Delay(unsigned int i);

void t1(void) interrupt 3 using 0
{
  TH1=(65536-200)/256;
  TL1=(65536-200)%256;
  CLK=~CLK;
}
void TimeInitial()
{ 
  TMOD=0x10;
  TH1=(65536-200)/256;
  TL1=(65536-200)%256;
  EA=1;
  ET1=1;
  TR1=1;
}
void Delay(unsigned int i)
{
  unsigned int j;
  for(;i>0;i--)
  {
   for(j=0;j<125;j++)
  {;}
  }
}

void Display()
{ 
  P1=dispbitcode[dispbuf[3]];
  P30=1;
  P31=0;
  P32=0;
  P33=0;
  Delay(7);
  P1=0xff;
  P1=dispbitcode[dispbuf[2]];
  P30=0;
  P31=1;
  P32=0;
  P33=0;
  Delay(7); 
  P1=0xff;
  P1=dispbitcode[dispbuf[1]];
  P30=0;
  P31=0;
  P32=1;
  P33=0;
  Delay(7);
  P1=0xff;
  P1=dispbitcode[dispbuf[0]];
  P30=0;
  P31=0;
  P32=0;
  P33=1;
  Delay(7);
  P1=0xff;
}
void main()
{
  TimeInitial();
  while(1)
  {
    ST=0;
    OE=0;
    ST=1;
    ST=0;
    P34=0;
    P35=0;
    P36=0;
    while(EOC==0);
    OE=1;
    getdata=P0;
    OE=0;
    temp=getdata*1.0/255*100;
    dispbuf[0]=temp%10;
    dispbuf[1]=temp/10%10;
    dispbuf[2]=temp/100%10;
    dispbuf[3]=temp/1000;
    Display();
  }
}