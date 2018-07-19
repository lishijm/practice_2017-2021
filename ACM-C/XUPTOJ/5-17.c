#include<stdio.h>
int main(){
	int n,i,j,k,t=0,sum=0;//t用来标记 
	scanf("%d",&n);
	
	for(i=1;i<=(n+1)/2;i++){
		for(j=i;sum<n;j++){
			sum=sum+j;
		}
		j--;
		if(sum==n){
			t=1;
			printf("%d=",n);
			for(k=i;k<j;k++){
				printf("%d+",k);
			}
			printf("%d\n",k);
		}
		sum=0;
	}
	if(t!=1){
		printf("NONE");
	}
	return 0;
}
