#include<stdio.h>
int main()
{
	int m,n,a,b,c;
	scanf("%d %d",&m,&n);
	a=m;b=n;
	while(n!=0)
	{
		c=m%n;
		m=n;
		n=c;
	}
	printf("%d %d",m,a*b/m);
	return 0;
}
