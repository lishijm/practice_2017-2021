#include<reg52.h>
void ser() interrupt 4{
    RI=0;
    P1=SBUF;
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
        if(!RI){
            RI=0;
            P1=SBUF;
        }
    }
}