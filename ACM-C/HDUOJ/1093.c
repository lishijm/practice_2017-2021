#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,m,i,j,num,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum=0;
        scanf("%d",&m);
        for(j=1;j<=m;j++){
            scanf("%d",&num);
            sum+=num;
        }
        printf("%d\n",sum);
    }
    return 0;
}
