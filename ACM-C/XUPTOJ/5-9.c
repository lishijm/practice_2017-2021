#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,t=0,sn,num=1;
	scanf("%d %d",&a,&n);
	while(num<=n)
	{
		t=t*10+a;
		sn+=t;
		num++;
	}
	printf("%d",sn);
	
	return 0;
}
