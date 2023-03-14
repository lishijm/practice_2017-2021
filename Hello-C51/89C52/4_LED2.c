//定时器
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;//段选锁存器使能接口
sbit wela=P2^7;//位选锁存器使能接口
sbit D1=P1^0;
uint numd,numw,tt;
uchar code table[]={
    0X3F,0X06,0X5B,0X4F,
    0X66,0X6D,0X7D,0X07,
    0X7F,0X6F,0X77,0X7C,
    0X39,0X5E,0X79,0X71
};
uchar code tablewe[]={
    0XFE,0XFD,0XFB,0XF7,0XEF,0XDF
};
void exter0() interrupt 1{//interrupu为中断序号，0为最高级中断
    TH0=(65536-50000)/256;//高八位
    TL0=(65536-50000)%256;//第八位
    tt++;
}
void main(){
    numd=0;
    numw=0;
    tt=0;
    TMOD=0X01;//设置定时器0为工作方式1
    TH0=(65536-50000)/256;//高八位
    TL0=(65536-50000)%256;//第八位
    EA=1;//开总中断
    ET0=1;//开定时器0中断
    EX0=1;//开外部中断0
    TR0=1;//启动定时器0
    wela=1;//使能端高电平接受，低电平锁存保持
    P0=tablewe[0];
    wela=0;
    dula=1;
    P0=table[0];
    dula=0;
    while(1){
        if(tt==20){
            tt=0;
            numd++;
            numw++;
            if(numw==6){
                numw=0;
            }
            if(numd==16){
                numd=0;
            }
            wela=1;
            P0=tablewe[numw];
            wela=0;
            dula=1;
            P0=table[numd];
            dula=0;
        }
    }
}