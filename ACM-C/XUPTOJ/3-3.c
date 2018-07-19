#include <stdio.h>
int main()
{
	int h,m;
	scanf("%d",&m);
	
	h=m/60;
	m=(m%60)%60;
	
	printf("%d:%d",h,m);
	
	return 0;
}
