#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,a,b,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
    return 0;
}
