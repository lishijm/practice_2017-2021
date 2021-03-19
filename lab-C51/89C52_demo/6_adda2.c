#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit wr=P3^6;
sbit dacs=P3^2;
sbit dula=P2^6;
sbit wela=P2^7;
sbit l1=P1^0;
uint temp,tn,flag;
void exter0() interrupt 1{//interrupu为中断序号，0为最高级中断
    TH0=(65536-200)/256;//高八位
    TL0=(65536-200)%256;//第八位
    tn++;
}
void main(){
    tn=0;
    wr=0;
    dacs=0;
    temp=0;
    flag=1;
    TMOD=0X01;//设置定时器0为工作方式1
    TH0=(65536-200)/256;//高八位
    TL0=(65536-200)%256;//第八位
    EA=1;//开总中断
    ET0=1;//开定时器0中断
    EX0=1;//开外部中断0
    TR0=1;//启动定时器0
    wela=1;
    P0=0xff;
    wela=0;
    dula=1;
    P0=0;
    dula=0;
    while(1){
        if(tn==125){
            tn=0;
            if(flag==1){
                switch(temp){
                    case 0x00:temp=0x01;
                        break;
                    case 0x01:temp=0x03;
                        break;
                    case 0x03:temp=0x07;
                        break;
                    case 0x07:temp=0x0f;
                        break;
                    case 0x0f:temp=0x1f;
                        break;
                    case 0x1f:temp=0x3f;
                        break;
                    case 0x3f:temp=0x7f;
                        break;
                    case 0x7f:temp=0xff;
                        break;
                    case 0xff:flag=0;
                        break;
                }
            }
            else if(flag==0){
                switch(temp){
                    case 0xff:temp=0x7f;
                        break;
                    case 0x7f:temp=0x3f;
                        break;
                    case 0x3f:temp=0x1f;
                        break;
                    case 0x1f:temp=0x0f;
                        break;
                    case 0x0f:temp=0x07;
                        break;
                    case 0x07:temp=0x03;
                        break;
                    case 0x03:temp=0x01;
                        break;
                    case 0x01:temp=0x00;
                        break;
                    case 0x00:flag=1;
                        break;
                }
            }
        }
        P0=temp;
    }
}