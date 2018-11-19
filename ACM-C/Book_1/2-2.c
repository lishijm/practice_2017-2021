#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int a,b,c;//a为三排，b为五排，c为七排
    int num,i=1,flag=0;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        for(num=1;num<=100;num++){
            if(num%3==a&&num%5==b&&num%7==c){
                printf("case %d: %d",i,num);
                flag=1;
                num=101;
            }
        }
        if(flag==0){
            printf("case %d: No answer",i);
        }
        i++;
        flag=0;
    }
    return 0;
}
