#include<stdio.h>
#include<math.h>
int prm(int x){
    int i;
    for(i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
}
int main(){
    int x,y,i;
    scanf("%d %d",&x,&y);
    for(i=x;i<=y;i++){
        if(prm(i)==0){
            continue;
        }
        else{
            printf("%d ",i);
        }
    }
    return 0;
}
