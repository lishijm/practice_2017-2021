#include<stdio.h>
int main(){
	int n,a,b=0,c=0,d=0;//n为输入的奇数
	scanf("%d",&n);
	if(n==1){
		printf("*");
	}
	else{
		printf("*\n");
		for(a=1;a<=(n-1)/2;a++){
			printf("*");
			while(b<(2*a-1)){//这是一个管行的循环 
				printf("+");
				b++;
			}
			b=0; 
			printf("*\n");
		}
		for(c=1;c<=(n-3)/2;c++){
			printf("*");
			while(d<(n-2*(c+1))){//这是一个管行的循环 
				printf("+");
				d++;
			}
			d=0;
			printf("*\n");
		}
		printf("*");
	}
	return 0;
} 
