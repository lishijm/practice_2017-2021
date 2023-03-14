//中断操作
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;//段选锁存器使能接口
sbit wela=P2^7;//位选锁存器使能接口
sbit D1=P1^0;
uint numw,numd;
uchar code tablewe[]={
    0XFE,0XFD,0XFB,0XF7,0XEF,0XDF
};
uchar code table[]={
    0X3F,0X06,0X5B,0X4F,
    0X66,0X6D,0X7D,0X07,
    0X7F,0X6F,0X77,0X7C,
    0X39,0X5E,0X79,0X71
};
void delay(uint dtime){
    uint x;
    for(;dtime>0;dtime--)
        for(x=10;x>0;x--);
}
void main(){
    numw=0;
    while(1){
        for(numd=1;numd<7;numd++){
            if(numw==6){
                numw=0;
            }
            wela=1;//使能端高电平接受，低电平锁存保持
            P0=tablewe[numw];
            wela=0;
            dula=1;
            P0=table[numd];
            dula=0;
            numw++;
            delay(10);
        }
    }
}