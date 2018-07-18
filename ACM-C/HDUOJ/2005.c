#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5,6};
    int *p=a;
    printf("%d",*(p+2));
    return 0;
}
