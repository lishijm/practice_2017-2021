#include<stdio.h>
int main()
{
	int a,sum,num=0;
	scanf("%d",&a);
	
	while(a!=-1)
	{
		sum+=a;
		num++;
		scanf("%d",&a);
	}
	printf("%d %.2f",sum,1.0*sum/num);
	
	return 0;
}
