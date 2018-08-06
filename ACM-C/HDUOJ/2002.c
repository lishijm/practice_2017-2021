#include<stdio.h>
#define PI 3.1415927
int main(int argc, char const *argv[])
{
    double rad,v;
    while(scanf("%lf",&rad)!=EOF){
        getchar();
        v=(4.0*PI*rad*rad*rad)/3.0;
        printf("%.3lf\n",v);
    }

    return 0;
}
