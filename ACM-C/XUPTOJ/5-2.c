#include<stdio.h>
int main()
{
	int n,num=0;
	float fn,tn,sn;
	scanf("%d",&n);
	while(num<n)
	{
		num++;
		fn=1./num;
		num++;
		tn=1./num;
		sn+=fn-tn;
	}
	printf("%.2f",sn);
	return 0;
}
