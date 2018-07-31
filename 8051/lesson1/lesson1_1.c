//点亮所有发光管
#include<reg52.h>

int main()
{
    sbit D1=P1^0; 
    sbit D2=P1^1; 
    sbit D3=P1^2; 
    sbit D4=P1^3; 
    sbit D5=P1^4; 
    sbit D6=P1^5; 
    sbit D7=P1^6; 
    sbit D8=P1^7; 
    
    D1=0; 
    D2=0; 
    D3=0; 
    D4=0;
    D5=0;
    D6=0;
    D7=0; 
    D8=0; 
}
