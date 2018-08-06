#include<stdio.h>
#include<stdlib.h>

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

void Savefile(int year){
	FILE *fp;
	int month,day,space,flag=0,returnv,returnv_4;//space为空格变量 
	int dpm[12]={31,28,31,30,31,30,31,31,30,31,30,31};//每月天数 
	
	if(year%4==0&&year%100!=0||year%400==0){
		dpm[1]=29;
	}
	else{
		dpm[1]=28;
	}
	//文件操作
	fp=fopen("date.txt","w");
	if(fp==NULL){
		printf("Wrong!\n");
		exit(0);
	}
	fprintf(fp,"%d\n\n",year);
	for(month=1;month<=12;month++){
		switch(month){
			case  1:fprintf(fp,"一月\n");break;
			case  2:fprintf(fp,"二月\n");break;
			case  3:fprintf(fp,"三月\n");break;
			case  4:fprintf(fp,"四月\n");break;
			case  5:fprintf(fp,"五月\n");break;
			case  6:fprintf(fp,"六月\n");break;
			case  7:fprintf(fp,"七月\n");break;
			case  8:fprintf(fp,"八月\n");break;
			case  9:fprintf(fp,"九月\n");break;
			case 10:fprintf(fp,"十月\n");break;
			case 11:fprintf(fp,"十一月\n");break;
			case 12:fprintf(fp,"十二月\n");break;
		}
		fprintf(fp,"Mon Tue Wed Thu Fri Sat Sun \n");
		//每月1日需要判断是星期几然后通过占位实现空格
		//空格为四倍的返回值 
		//只需判断每月一日的星期 
		for(day=1;day<=dpm[month-1];day++){
			returnv=week(month,day,year);
			if(day==1){
				returnv_4=4*returnv;
				for(space=0;space<=returnv_4;space++){
					fprintf(fp," ");
				}
			}
			fprintf(fp,"%-4d",day);
			if(returnv==6){
				fprintf(fp,"\n");
			}
			if(day==dpm[month-1]){
				fprintf(fp,"\n");
			}
		}
	}
	fclose(fp);
}

int main(){
	int year,x;
	scanf("%d",&year);
	//改写为存储函数
	Savefile(year);
	
	return 0;
}
