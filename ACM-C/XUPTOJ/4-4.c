#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,x1,x2,t;
	scanf("%f %f %f",&a,&b,&c);
	
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	
	if(x1>=x2)
	t=x1;x1=x2;x2=t;

	printf("x1=%.2f,x2=%.2f",x1,x2);
	
	return 0;
}
