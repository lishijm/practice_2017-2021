#include <stdio.h>
int main ()
{
	float a,b,h; //浮点变量才可以算出小数点后的值 
	double s;
	
	scanf("%f %f %f",&a,&b,&h);
	s=(a+b)*h/2;
	
	printf("%f",s);
	
	return 0;
}
