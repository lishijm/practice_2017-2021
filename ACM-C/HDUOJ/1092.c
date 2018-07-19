#include<stdio.h> 
int main(int argc, char const *argv[])
{
    int n,num,sum,i;
    while(scanf("%d",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            sum+=num;
        }
        if(sum!=0){
            printf("%d\n",sum);
        }
    }
    return 0;
}
