#include<stdio.h>
int pri(int n,int m){
    int i,flag_1=0,flag_2=0,flag_e=0;
    for(i=2;i<n;i++){
        if(n%i==0){
            flag_1=1;
        }
    }
    for(i=2;i<n;i++){
        if(m%i==0){
            flag_2=1;
        }
    }
    if(flag_1==1||flag_2==1){
        flag_e=1;
    }
    return flag_e;
}
int main(){
    int x,y,t,p;
    scanf("%d %d",&x,&y);
    t=x;
    while(t<=y){
        if(t%2==0){
            t++;
        }
        if(t+2>y){
            break;
        }
        p=pri(t,t+2);
        if(p==0){
            printf("(%d,%d)",t,t+2);
        }
        t++;
    }
    return 0;
}
