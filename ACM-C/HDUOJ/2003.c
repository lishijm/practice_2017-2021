#include<stdio.h>
int main(int argc, char const *argv[])
{
    double num;
    while(scanf("%lf",&num)!=EOF){
        getchar();
        if(num<0){
            num=0.0-num;
        }
        printf("%.2lf\n",num);

    }
    return 0;
}