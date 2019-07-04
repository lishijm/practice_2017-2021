#include<stdio.h>
int data[2]={100,200};
int moredata[2]={300,400};
int main(){
    int*p1,*p2,*p3;

    p1=p2=data;
    p3=moredata;
    printf("%d %d %d\n",*p1,*p2,*p3);

    return 0;
}