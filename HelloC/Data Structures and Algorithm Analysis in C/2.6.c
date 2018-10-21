//最大子序列之和
//算法二
#include<stdio.h>
#include<stdlib.h>
int MSS(int A[],int N){
    int ThisSum,MaxSum,i,j;
    MaxSum=0;
    for(i=0;j<N;i++){
        ThisSum=0;
        for(j=i;j<N;j++){
            ThisSum+=A[j];
            
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
