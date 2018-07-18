/*???????¨¦?????¡Á?? */ 
#include<stdio.h>
//???¡¦?????????¡Á?? 
long fact(int n){
	long ans;
	
	for (ans=1;n>1;n--){
		ans*=n;
	}
	return ans;
}
//???????¨¦?????????¡Á?? 
long rfact(int n){
	long ans;
	
	if (n>0){
		ans=n*rfact(n-1);
	}
	else{
		ans=1;
	}
	return ans;
}

int main(){
	int num;
	
	printf("This progream caculates factorials.\n");
	printf("Enter a value in the range 0-12(q to quite):\n");
	
	while(scanf("%d",&num)==1){
		if(num<0){
			printf("No nrgative numbers,pleases.\n");
		}
		else if(num>12){
			printf("Keep input under 13.\n");
		}
		else{
			printf("Loop: %d factorial=%ld\n",num,fact(num));
			printf("recursion: %d factorial = %ld\n",num,rfact(num));
		}
		printf("Enter a value in the range 0-12 (q to quit):\n");
	}
	printf("Bye.\n");
	
	return 0;
}
