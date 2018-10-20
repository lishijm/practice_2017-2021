#include<stdio.h>
int main(int argc, char const *argv[])
{
    double n,sum=0;
    for(n=1;n<=100;n++){
        sum+=n;
    }
    printf("%f %.1f",sum,sum/100);
    return 0;
}
