#include <stdio.h>
int main()
{
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	
	max=a;
	if(a<b)
	max=b;
	if(a<c)
	max=c;
	
	printf("%d",max);
	
	return 0;
	
	
}

