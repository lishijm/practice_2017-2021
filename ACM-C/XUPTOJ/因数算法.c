#include<stdio.h>
int main ()
{
	int x,i,s;
	scanf("%d",&x);
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		{
			s+=i;
		}
	}
	printf("%d",s);
    
	return 0;
} 
