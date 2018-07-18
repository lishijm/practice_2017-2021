#include<stdio.h>
int main(){
	int n,i,j=0;
	scanf("%d",&n);
	int num[n],sum,k;
	for(i=1;i<=n;i++){
		if(i%2==1){
			num[j]=i;
			j++;
		}
	}
	for(k=0;k<j;k++){
		sum+=num[k];
	}
	printf("%d",sum);
	
	return 0;
}
 
