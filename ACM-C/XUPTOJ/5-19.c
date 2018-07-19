#include<stdio.h>
int main(){
	int dpm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day,time,i;//i计数  
	
	scanf("%04d-%02d-%02d %d",&year,&month,&day,&time);
	
	for(i=1;i<=time;i++){
		day++;
		if(day>dpm[month-1]){
			month++;
			day=1;//归一 
			if(month>12){
				year++;
				month=1;//归一 
				
				if(year%4==0&&year%100!=0||year%400==0){
					dpm[1]=29;
				}
				else{
					dpm[1]=28;
				}
			}
		}
	}
	printf("%04d-%02d-%02d",year,month,day);
	
	return 0;
}
