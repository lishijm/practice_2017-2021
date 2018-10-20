#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    if(n<=10){
        printf("该数小于等于十");
    }
    if(10<n&&n<=50){
        printf("该数大于十小于等于五十");
    }
    if(50<=n){
        printf("该数大于五十");
    }
    return 0;
}
