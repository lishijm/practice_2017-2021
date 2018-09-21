#include<stdio.h>
int main(){
    int n,i,max=0,maxn=1,sum=0,num;//i???????? 
    float sumf,nf;
    scanf("%d\n",&n);
    int mark[n];
    for(i=0;i<n;i++){
        scanf("%d",&mark[i]);
        sum+=mark[i];
        if(mark[i]>max){
            max=mark[i];
            maxn=i+1;
        }
    }
    sumf=sum;
    nf=n;
     
    printf("%d %d %.2f",maxn,max,sumf/nf);
     
    return 0;
} 
