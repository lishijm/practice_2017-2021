#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit wr=P3^6;
sbit dacs=P3^2;
sbit dula=P2^6;
sbit wela=P2^7;
void main(){
    dula=1;
    P0=0;
    dula=0;
    wela=1;
    P0=0xff;
    wela=0;
    wr=0;
    dacs=0;
    P0=0x50;
    while(1);
}