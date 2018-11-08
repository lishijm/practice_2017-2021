#include<stdio.h>
int main(int argc, char const *argv[])
{
    int f;
    float c;
    scanf("%dF",&f);
    c=5*(f-32)/9.;
    printf("%.3fC",c);
    return 0;
}
