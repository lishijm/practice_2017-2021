//独立键盘
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit l1=P1^0;
sbit s1=P3^4;
sbit dula=P2^6;//段选锁存器使能接口
sbit wela=P2^7;//位选锁存器使能接口
uint num;
uchar code table[]={
    0X3F,0X06,0X5B,0X4F,
    0X66,0X6D,0X7D,0X07,
    0X7F,0X6F,0X77,0X7C,
    0X39,0X5E,0X79,0X71
};
void delay(uint time){
    uint x;
    for(;time>0;time--){
        for(x=500;x>0;x--);
    }
}
void main(){
    num=0;
    wela=1;
    P0=0XFE;
    wela=0;
    dula=1;
    P0=table[0];
    dula=0;
    P3=0XFF;
    while(1){
        if(s1==0){
            delay(10);
            if(s1==0){
                l1=0;
                num++;
            }
            while(!s1);//松手检测,按下s1程序在此停住成为死循环
            delay(10);
            while(!s1);
            if(num==10){
                num=0;
            }
        }
        else{
            l1=1;
        }
        dula=1;
        P0=table[num];
        dula=0;
    }
}