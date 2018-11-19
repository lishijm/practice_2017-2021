#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        for(k=1;k<=n-i;k++){
            printf(" ");
        }
        for(j=1;j<(i*2);j++){
            printf("*");
        }
        for(k=1;k<=n-i;k++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}