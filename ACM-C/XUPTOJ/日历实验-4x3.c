#include<stdio.h>
#include<stdlib.h>
int week(int month,int day,int year);

int week(int month,int day,int year){
	int m=month;int d=day;int y=year;
	int x; 
	if(m==1||m==2){
    	m+=12;
    	y--;
	}
	int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//使用基姆拉尔森计算公式

	switch(Week){
    	case 0: x=0; break;
    	case 1: x=1; break;
    	case 2: x=2; break;
    	case 3: x=3; break;
		case 4: x=4; break;
    	case 5: x=5; break;
    	case 6: x=6; break;
	}
	return x; 
}
int main(){
	int year,month,day,space,flag=0,returnv,returnv_4;//space为空格变量 
	int dpm[12]={31,28,31,30,31,30,31,31,30,31,30,31};//每月天数 
	scanf("%d",&year);
	if(year%4==0&&year%100!=0||year%400==0){
		dpm[1]=29;
	}
	else{
		dpm[1]=28;
	}
	for(month=1;month<=12;month++){
		switch(month){
			case  1:printf("一月\n");break;
			case  2:printf("二月\n");break;
			case  3:printf("三月\n");break;
			case  4:printf("四月\n");break;
			case  5:printf("五月\n");break;
			case  6:printf("六月\n");break;
			case  7:printf("七月\n");break;
			case  8:printf("八月\n");break;
			case  9:printf("九月\n");break;
			case 10:printf("十月\n");break;
			case 11:printf("十一月\n");break;
			case 12:printf("十二月\n");break;
		}
		printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\t\n");
		//每月1日需要判断是星期几然后通过占位实现空格
		//空格为四倍的返回值 
		//只需判断每月一日的星期 
		for(day=1;day<=dpm[month-1];day++){
			returnv=week(month,day,year);
			if(day==1){
				returnv_4=4*returnv;
				for(space=0;space<=returnv_4;space++){
					printf("\t");
				}
			}
			printf("%d\t",day);
			if(returnv==6){
				printf("\n");
			}
			if(day==dpm[month-1]){
				printf("\n");
			}
		}
	}
	return 0;
}
