#include<stdio.h>
int prm(int x){
    int i,flag=1;
    for(i=2;i<x;i++){
        if(x%i==0)
            flag=0;
    }
    return flag;
}
int main(){
    int x,y,i,k,t,r,flag_1,flag_2;
    scanf("%d %d",&x,&y);
    for(i=x;i<=y;i++){
        flag_1=prm(i);
        if(flag_1==1){
            k=i;
            r=0;
            while(k>0){
                t=k%10;
                k=k/10;
                r=10*r+t;
            }
            flag_2=prm(r);
            if(flag_2==1){
                printf("%d ",i);
            }
        }
    }
    return 0;
}
