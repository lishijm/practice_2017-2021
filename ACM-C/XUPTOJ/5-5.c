#include<stdio.h>
int jiecheng(int n)
{
	int f=1;
	while(n>=1)
	{
		f=n*f;
		n--;
	}
	return f;
}
int main()
{
	int sn,n;
	scanf("%d",&n);
	while(n>=1)
	{
		sn+=jiecheng(n);
		n--;
	}
	printf("%d",sn);
	
	return 0;
}
