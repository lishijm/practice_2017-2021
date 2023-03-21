#include<reg52.h>
#define unchar unsigned char
#define unint unsigned int
sbit lcden=P3^4;
sbit lcdrs=P3^5;
sbit dula=P2^6;
sbit wela=P2^7;
unchar code table_1[]="HELLO WORLD!";
unchar code table_2[]="I AM LISHIJM";
unchar num;
void delay(unint time){
    unint x,y;
    for(x=time;x>0;x--){
        for(y=110;y>0;y--);
    }
}
void write_com(unchar com){
    lcdrs=0;
    P0=com;
    delay(5);
    lcden=1;
    delay(5);
    lcden=0;
}
void write_data(unchar date){
    lcdrs=1;
    P0=date;
    delay(5);
    lcden=1;
    delay(5);
    lcden=0;
}
void inition(){
    dula=0;
    wela=0;
    lcden=0;
    write_com(0x38);
    write_com(0x0e);
    write_com(0x06);
    write_com(0x01);
    write_com(0x80+0x10);

}
void main(){
    inition();
    for(num=0;num<12;num++){
        write_data(table_1[num]);
        delay(20);
    }
    //write_com(0x01);//clean
    write_com(0x80+0x54);//enter pointers
    for(num=0;num<12;num++){
        write_data(table_2[num]);
        delay(20);
    }
    for(num=0;num<16;num++){
        write_com(0x18);
        delay(200);
    }
    while(1);
}