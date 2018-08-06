#include<stdio.h>
int fac(int n){
	int i;
	for(i=2;i<=n;i++){
		if(n%i==0){
			if(n==i){
				printf("%d ",n);
				break;
			}
			else{
				printf("%d ",i);
				fac(n/i);
				break;
			}
		}
	}	
}
int main(){
	int n;
	scanf("%d",&n);
	fac(n);
}
