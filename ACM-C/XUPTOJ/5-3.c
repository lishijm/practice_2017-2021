#include<stdio.h>
int main()
{
	int a,b,c,s;
	scanf("%d",&a);
	while(a>=1)
	{
		b=a%10;
		if(b%2)
		{
			c=b*b;
			s+=c;
		}
		a=a/10;
	}
	printf("%d",s);
	
	return 0;
}
