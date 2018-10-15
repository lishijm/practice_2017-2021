#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    float N,k,times;
    clock_t start,finish;
    scanf("%f",&N);
    start=clock();
    while(N--)
    finish=clock();
    times=(float)(finish-start);
    printf("%f\n%fs",k,times);
    return 0;
}
