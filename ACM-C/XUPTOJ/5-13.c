#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int i,n,ddsx,bai,shi,ge,t;//ddsx意为待定水仙花数 
	scanf("%d\n",&n);
	scanf("%d",&ddsx);
	for(i=1;i<=n;i++)
	{
		bai=ddsx/100;
		shi=(ddsx%100)/10;
		ge=ddsx%10;
	    t=ge*ge*ge+shi*shi*shi+bai*bai*bai;//t为水仙花数算法
		//下为判断部分 
	    if(t==ddsx)
	    {
	    	printf("%d是水仙花数\n",ddsx);
		}
		else
		{
			printf("%d不是水仙花数\n",ddsx);
		}
		scanf("%d",&ddsx);
	} 
	return 0;
}
