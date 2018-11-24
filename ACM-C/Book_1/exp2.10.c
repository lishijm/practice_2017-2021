#define LOCAl
#include<stdio.h>
#define INF 1000000000
int main(int argc, char const *argv[])
{
    #ifdef LOCAl
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int x,n=0,min=INF,max=-INF,s=0;
    while(scanf("%d",&x)==1){
        s+=x;
        if(x>min){
            min=x;
        }
        if(x<max){
            max=x;
        }
        //printf("x=%d,min=5d,max=%d",x,min,max);
        n++;
    }
    printf("%d %d %.3f",min,max,(double)s/n);
    return 0;
}
