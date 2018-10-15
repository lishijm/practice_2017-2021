#include<stdio.h>
int sum(int N){
    int i,Partialsum;
    
    Partialsum=0;
    for(i=1;i<=N;i++){
        Partialsum+=i*i*i;
    }
    return Partialsum;
}
int main(int argc, char const *argv[])
{
    int N,suma;
    scanf("%d",&N);
    suma=sum(N);
    printf("%d",suma);
    return 0;
}
