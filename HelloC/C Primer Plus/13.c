#include<stdio.h>
int main(){
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a<b){
		max=b;
	}
	else{
		max=a;
	}
	if(max<c){
		max=c;
	}
	printf("%d",max);
	
	return 0;
} 
