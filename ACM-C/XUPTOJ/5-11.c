#include<stdio.h>
int main()
{
	int m,n,num=1;//nÊÇ´ÎÊı 
	float t,x,h,s;
	scanf("%d %d",&m,&n);
	t=m;x=m;
	while(num<=n)
	{
		h=t/2;
		t=h;
		s+=2*h;
		num++;
	}
	printf("%.2f %.2f",h,x+s-2*h);
	
	return 0;
}
