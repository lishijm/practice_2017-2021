#include<stdio.h>
int main(){
	int n,i,t;
	scanf("%d\n",&n);
	int num[n];
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(t=n-1;t>=0;t--){
		printf("%d ",num[t]);
	}
	return 0;
} 
