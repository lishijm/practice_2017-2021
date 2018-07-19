#include<stdio.h>
#define SIZE 4
int main(){
	int valuel=44,arr[SIZE],value2=88,i;
	
	printf("valuel=%d,valude2=%d\n",valuel,value2);
	for(i=-1;i<=SIZE;i++){
		printf("%2d %d\n",i,arr[i]);
	}
	printf("value1=%d value2=%2d",valuel,value2);
	
	return 0;
} 
