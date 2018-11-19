#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n*2;i++,i++){
        printf("%d\n",i);
    }
    return 0;
}
