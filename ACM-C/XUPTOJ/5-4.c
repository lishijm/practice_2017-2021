#include<stdio.h>
int main()
{
	int n,f=1;
	scanf("%d",&n);
	while(n>=1)
	{
		f=n*f;
		n--;
	}
	printf("%d",f);
	
	return 0;
}
