#include<reg52.h>
unsigned char a,flag;
void ser() interrupt 4{
    RI=0;
    P1=SBUF;//此SBUF为发送缓存器里的值
    a=SBUF;
    flag=1;
}
void main(){
    TMOD=0X20;
    TH1=0XFD;
    TL1=0XFD;
    TR1=1;
    REN=1;
    SM0=0;
    SM1=1;
    EA=1;
    ES=1;
    while(1){
        if(flag==1){
            flag=0;
            SBUF=a;//此SBUF为接收缓冲器里的值
        }
    }
}