#include<stdio.h>
int main()
{
	int d;
	float a,b,c;
	char q;
	scanf("%f%c%f",&a,&q,&b);
	d=("%d",q);
	
	if(q==43)
	c=a+b;
	
    if(q==45) 
	c=a-b;
	
	if(q==47)
	c=a/b;
	
	if(q==42)
	c=a*b;
	
	printf("%.2f%c%.2f=%.2f",a,q,b,c);
	
	return 0;
}
