//最大子序列和
//算法一
#include<stdio.h>
#include<stdlib.h>
int MSS(int A[],int N){
    int  ThisSum,MaxSum,i,j,k;
    MaxSum=0;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            ThisSum=0;
            for(k=i;k<=j;k++){
                ThisSum+=A[k];
            }
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}
int main(int argc, char const *argv[])
{
    int A[10]={11,12,13,14,15,16,17,18,19,20},N=5,sum;
    sum=MSS(A,N);
    printf("%d",sum);    
    return 0;
}
