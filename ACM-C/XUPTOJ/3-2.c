#include <stdio.h>
#include <math.h>
#define PI 3.14
int main()
{
    float r,h,v;
	scanf("%f %f",&r,&h);
	
	v=(PI*r*r*h)/3;
	
	printf("%.2f",v);
	
	return 0;
}
