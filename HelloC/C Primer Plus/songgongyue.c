#include<stdio.h>
main()
{
	int m,n,a,b,c,d,e,f,i;
	scanf("%d %d",&m,&n);
	for(i=n;i>=1;i--)
	{
		a=m%i;
		b=n%i;
		if(a==b&&a==0&&b==0)
		break;
	}
	for(d=1;d>=m;d++)
	{
		e=d%m;
		f=d%m;
		if(e==0&&f==0)
		break;
	}
	printf("%d %d",i,d);
}
