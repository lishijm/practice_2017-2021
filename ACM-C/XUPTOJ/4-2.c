#include<stdio.h>
int main ()
{
	int day,week;
	scanf("%d",&day);
	
	week=day%7;
	
	if(week==1)
	printf("星期一"); 
	
	if(week==2)
	printf("星期二"); 
	
	if(week==3)
	printf("星期三"); 
	
	if(week==4)
	printf("星期四"); 
	
	if(week==5)
	printf("星期五"); 
	
	if(week==6)
	printf("星期六"); 
	
	if(week==0)
	printf("星期天"); 
	
	return 0; 
}
