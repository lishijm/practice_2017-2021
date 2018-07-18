#include<stdio.h>
int main()
{
	int x,n=1,i=1,s=0;//yÊÇÒòÊı 
	scanf("%d",&x);
	while(n<=x)
	{
		s=0;
		 
		for(i=1;i<n;i++)
		{
			if(n%i==0)
			s=i+s;
		}
		if(s==n)
		{
			printf("%d ",n);
		}
		n++;
	}
	return 0;
}
