#include<stdio.h>
#define A 30
int main(){
	int sq_feet,cans;
	printf("Enter number of square feet to be pained:\n");
	
	while(scanf("%d",&sq_feet)==1){
		cans=sq_feet/A;
		cans+=((sq_feet%A==0))?0:1;
		
		printf("you need %d %s of paint.\n",cans,cans==1?"can":"cans");
		printf("Enter next value(q to quit):\n");
	}
	return 0;
}
