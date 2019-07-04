//二进制打印程序 
#include<stdio.h>

void to_bin(unsigned long n){
	int r;
	r=n%2;
	
	if(n>=2){
		to_bin(n/2);
	}
	putchar(r==0?'0':'1');
	
	return;
} 

int main(){
	unsigned long number;
	printf("Enter an integar (q to quit):\n");
	while(scanf("%lu",&number)==1){
		printf("Binary equivalent: ");
		to_bin(number);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");	
	}
	printf("Done.\n");
	
	return 0;
}
