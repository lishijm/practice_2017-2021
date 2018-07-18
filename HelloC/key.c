#include<stdio.h>
int main(){
	int key[7],i;
	char answer[7]={"123456\0"};
	for(i=0;i<6;i++){
		key[i]=getch();
		printf("*");
	}
	key[6]='\0';
	if(strcmp(key,answer)==0){
		printf("\nT");
	}
	else{
		printf("\nF");
	}
	return 0;
}
