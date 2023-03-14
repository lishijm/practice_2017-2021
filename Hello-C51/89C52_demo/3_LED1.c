//中断操作
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;//段选锁存器使能接口
sbit wela=P2^7;//位选锁存器使能接口
sbit D1=P1^0;
uint num;
uchar code table[]={
    0X3F,0X06,0X5B,0X4F,
    0X66,0X6D,0X7D,0X07,
    0X7F,0X6F,0X77,0X7C,
    0X39,0X5E,0X79,0X71
};
void delay(uint dtime){
    uint x;
    for(;dtime>0;dtime--)
        for(x=200;x>0;x--);
}
void exter0() interrupt 0{//interrupu为中断序号，0为最高级中断
    D1=0;
}
void main(){
    EA=1;//开总中断
    EX0=1;//开外部中断0
    IT0=1;//电平边沿中断操作
    wela=1;//使能端高电平接受，低电平锁存保持
    P0=0XC0;
    wela=0;
    while(1){
        for(num=0;num<16;num++){
            D1=1;
            dula=1;
            P0=table[num];
            dula=0;
            delay(1000);
        }
    }
}