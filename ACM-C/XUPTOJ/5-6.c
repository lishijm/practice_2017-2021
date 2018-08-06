#include<stdio.h>
int main(){
    int a,n,sum,i,t;
    t=sum=0;
    scanf("%d,%d",&a,&n);
    for(i=0;i<n;i++){
        t=t*10+a;
        sum+=t;
    }
    printf("sum=%d",sum);
    return 0;
}
