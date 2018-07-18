#include<stdio.h>
#define SIZE 50
int main(){
	int counter,evens[SIZE];
	
	for(counter=0;counter<SIZE;counter++){
		evens[counter]=2*counter;
		printf(evens[%d],counter);
	}
	return 0;
}
