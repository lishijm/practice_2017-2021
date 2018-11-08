#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,c;
    float avg;
    scanf("%d %d %d",&a,&b,&c);
    avg=(a+b+c)/3.;
    printf("%.3f",avg);
    return 0;
}
