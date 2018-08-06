#include "stdio.h"
void main()
{
int j,k,sum = 0;
for(k=2;k<=1000;k++)
{
    sum=0;
    for(j=1;j<k;j++)
    if(k%j==0)
    sum=sum+j;
    if(sum==k)
    printf("%d ",k);
}
}
