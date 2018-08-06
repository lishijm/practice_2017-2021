#include<stdio.h>
int fac();

int fac(int n){
	int fac=1,i;
	for(i=n;i>0;i--){
		fac*=i;
	}
	return fac;
}
int main(){
	int num;
	scanf("%d",&num);
	printf("%d",fac(num));
	
	return 0;
} 
