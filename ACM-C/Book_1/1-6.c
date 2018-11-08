#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int a,b,c,tmp;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        tmp=a;
        a=b;
        b=tmp;
    }
    if(b>c){
        tmp=b;
        c=b;
        b=tmp;
    }
    if(a>c){
        tmp=a;
        b=a;
        a=tmp;
    }
    if(a+b>=c){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
