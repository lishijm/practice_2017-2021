#include<stdio.h>
int main(){
	int n,tmp,i,t,j;
	scanf("%d\n",&n);
	int num[n];
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(j=1;j<=n;j++){
		for(t=0;t<n-1;t++){
			if(num[t]>=num[t+1]){
				tmp=num[t];
				num[t]=num[t+1];
				num[t+1]=tmp;
			}
		}
	}
	for(t=0;t<n;t++){
		printf("%d ",num[t]);
	}
	return 0;
}
