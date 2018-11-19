#include<stdio.h>
int main(int argc, char const *argv[])
{
    long int n,m,i,j=1;
    double sum=0.;
    while(scanf("%ld %ld",&n,&m)!=EOF){
        if(n==0&&m==0){
            break;
        }
        else{
            for(i=n;i<=m;i++){
                sum+=(1.0/i/i);
            }
            printf("case%d: %.5f",j,sum);
            j++;
        }
        sum=0.0;
    }
        
    return 0;
}
