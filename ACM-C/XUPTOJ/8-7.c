#include<stdio.h>
int facs(int x){
	int i=1,s=0;
	for(i=1;i<x;i++){
		if(x%i==0)
            s=i+s;
    }
    return s;
}
int main(){
    int x,sum_1,sum_2,i,k;
    scanf("%d",&x);
    for(i=1;i<x;i++){
        sum_1=facs(i);
        if(sum_1>i&&facs(sum_1)==i){
            printf("(%d,%d)",i,sum_1);
        }
    }
    return 0;
}
