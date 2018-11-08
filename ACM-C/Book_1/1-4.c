#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int n;
    const double pi=acos(-1.0);
    scanf("%d",&n);
    printf("%f %f",sin(pi*n/180),cos(pi*n/180));
    return 0;
}
