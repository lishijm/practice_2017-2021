#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,max,temp;
    int num[5];
    for(i=0;i<5;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<5;i++){
        max=0;
        for(j=i;j<5;j++){
            if(num[j]>max){
                max=num[j];
            }
        }
        temp=num[max];
        num[max]=num[j];
        num[j]=temp;
    }
    for(i=0;i<5;i++){
        printf("%d",num[i]);
    }
    return 0;
}