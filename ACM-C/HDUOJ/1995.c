#include<stdio.h>
#include<stdlib.h>
int hanoi(int n,int k){
    int num;
    
}
int main(int argc, char const *argv[])
{
    int t;
    int h[t][2],result,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&h[i][0],&h[i][1]);
        result=hanoi(h[i][0],h[i][1]);
        printf("%d",result);
    }
    return 0;
}
