#include<stdio.h>
int Week_judge(int y,int m,int d){
	if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7,g;
    switch(iWeek){
    	case 0: g=0; break;
    	case 1: g=1; break;
    	case 2: g=2; break;
    	case 3: g=3; break;
    	case 4: g=4; break;
    	case 5: g=5; break;
    	case 6: g=6; break;
    }
    return g;
}

int main(){
	int date,year,month,day,n,i,x,g;
	int dpm[12]={31,28,31,30,31,30,31,31,30,31,30,31},dpmx[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d\n",&n);
	for(i=0;i<=n;i++){
		scanf("%d",&date);
		year=date/10000;
		month=(date/100)%100;
		day=date%100;
		if(year%4==0&&year%100!=0||year==0){
			if(day>dpmx[month-1]){
				i=0;
			}
			else{
				i=1;
			}
		}
		else{
			if(day>dpm[month-1]){
				i=0;
			}
			else{
				i=1;
			}
		}
		if(i==1){
			Week_judge(year,month,day);
			g=x;
			switch(x){
    			case 0: printf("%d星期一\n",date); break;
    			case 1: printf("%d星期二\n",date); break;
    			case 2: printf("%d星期三\n",date); break;
    			case 3: printf("%d星期四\n",date); break;
    			case 4: printf("%d星期五\n",date); break;
    			case 5: printf("%d星期六\n",date); break;
    			case 6: printf("%d星期日\n",date); break;
    		}
		}
		else if(i==0){
			printf("%d是非法日期",date);
		}
		while(getchar()!='\n'){
			continue;
		}
	}
	return 0;
}
