#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int i;
    for(i=100;i<=999;i++){
        if((i/100)*(i/100)*(i/100)+((i/10)%10)*((i/10)%10)*((i/10)%10)+(i%10)*(i%10)*(i%10)==i){
            printf("%d\n",i);
        }
    }
    return 0;
}
