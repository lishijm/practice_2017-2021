//矩阵键盘
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit l1=P1^0;
sbit s1=P3^4;
sbit dula=P2^6;//段选锁存器使能接口
sbit wela=P2^7;//位选锁存器使能接口
uint temp;
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
void keyboard(){
        P3=0Xfe;
        temp=P3;
        temp=temp&0xf0;
        if(temp!=0xf0){
            delay(10);
            if(temp!=0xf0){
                switch(temp){
                    case 0xe0:dula=1;
                              P0=table[0];
                              dula=0;
                              break;
                    case 0xd0:dula=1;
                              P0=table[1];
                              dula=0;
                              break;
                    case 0xb0:dula=1;
                              P0=table[2];
                              dula=0;
                              break;
                    case 0x70:dula=1;
                              P0=table[3];
                              dula=0;
                              break;
                }
            }//因为段选锁存器写在判断逻辑内，所以不用松手检测
        }
        P3=0Xfd;
        temp=P3;
        temp=temp&0xf0;
        if(temp!=0xf0){
            delay(10);
            if(temp!=0xf0){
                switch(temp){
                    case 0xe0:dula=1;
                              P0=table[4];
                              dula=0;
                              break;
                    case 0xd0:dula=1;
                              P0=table[5];
                              dula=0;
                              break;
                    case 0xb0:dula=1;
                              P0=table[6];
                              dula=0;
                              break;
                    case 0x70:dula=1;
                              P0=table[7];
                              dula=0;
                              break;
                }
            }//因为段选锁存器写在判断逻辑内，所以不用松手检测
        }
        P3=0Xfb;
        temp=P3;
        temp=temp&0xf0;
        if(temp!=0xf0){
            delay(10);
            if(temp!=0xf0){
                switch(temp){
                    case 0xe0:dula=1;
                              P0=table[8];
                              dula=0;
                              break;
                    case 0xd0:dula=1;
                              P0=table[9];
                              dula=0;
                              break;
                    case 0xb0:dula=1;
                              P0=table[10];
                              dula=0;
                              break;
                    case 0x70:dula=1;
                              P0=table[11];
                              dula=0;
                              break;
                }
            }//因为段选锁存器写在判断逻辑内，所以不用松手检测
        }
        P3=0Xf7;
        temp=P3;
        temp=temp&0xf0;
        if(temp!=0xf0){
            delay(10);
            if(temp!=0xf0){
                switch(temp){
                    case 0xe0:dula=1;
                              P0=table[12];
                              dula=0;
                              break;
                    case 0xd0:dula=1;
                              P0=table[13];
                              dula=0;
                              break;
                    case 0xb0:dula=1;
                              P0=table[14];
                              dula=0;
                              break;
                    case 0x70:dula=1;
                              P0=table[15];
                              dula=0;
                              break;
                }
            }//因为段选锁存器写在判断逻辑内，所以不用松手检测
        }
}
void main(){
    wela=1;
    P0=0Xc0;
    wela=0;
    dula=1;
    P0=0;
    dula=0;
    while(1){
        keyboard();
    }
}