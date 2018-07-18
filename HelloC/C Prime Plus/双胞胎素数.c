#include<stdio.h>
int main(){
	int x,y,m,i,flag=1;//i计数君，flag标记
	scanf("%d %d",&x,&y);
	if(x<=2){
		x=3;
	}
	for(m=x;m<=y;m++){
		for(i=2;i<m;i++){
			if(m%i==0||(m+2)%i==0){
				flag=0;
				break;
			}
		}
		if((m+2)>y){
			flag=0;
			break;
		}
		if(flag==1){
			printf("(%d,%d)",m,m+2);
		}
		flag=1;
	}
	return 0;
} 
