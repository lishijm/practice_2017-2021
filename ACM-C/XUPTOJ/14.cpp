#include<stdio.h>
int main(){
	int n,i,p;
	scanf("%d",&n);
	int num[n];
	num[0]=2;num[1]=3;
	for(i=0;i<n;i++){
		p=num[i]*num[i+1];
		if(p/10==0){
			num[i+2]=p;
		}
		else{
			num[i+2]=p/10;
			num[i+3]=p%10;
			i=i+1;
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",num[i]);
	}
	printf("%d#",num[n-1]);
	
	return 0;
}
