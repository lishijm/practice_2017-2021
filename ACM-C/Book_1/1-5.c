#include<stdio.h>
#define pr 95
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    float prr=n*pr;
    if(prr>=300){
        printf("%.2f",prr*0.85);
    }
    else{
        printf("%.2f",prr);
    }
    return 0;
}
