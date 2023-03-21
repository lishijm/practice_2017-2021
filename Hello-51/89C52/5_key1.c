#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit l1=P1^0;
sbit s1=P3^4;
void main(){
    P3=0XFF;
    while(1){
        if(s1==0){
            l1=0;
        }
        else{
            l1=1;
        }
    }
}