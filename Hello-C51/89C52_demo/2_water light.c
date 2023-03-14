#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit beep=P2^3; // 蜂鸣器接口定义
void delay(uint x){
    uint y;
    for(;x>0;x--)
        for(y=200;y>0;y--);
}
void main(){
    uint temp;
    temp=0XFE;
    P1=temp;
    while(1){
        beep=0;
        delay(200);
        temp=_crol_(temp,1);
        P1=temp;
    }
}