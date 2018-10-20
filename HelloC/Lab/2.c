#include<stdio.h>
int main(){
    int n,i,sum=0,j=0;
    scanf("%d",&n);
    for(i=10;i<=n;i++){
        sum+=i;
    }
    i=10;
    while(i<=n){
        if(i%3==0){
            j++;
        }
        i++;
    }
    printf("%d %d",sum,j);
    return 0;
}
