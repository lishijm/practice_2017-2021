#include<stdio.h>
int main(){
	int x,t,i,j,k,sumi=0;
	scanf("%d\n",&x);
	int fac[50];
	for(t=2;t<=x;t++){
		j=0;
		for(i=1;i<t;i++){
			if(t%i==0){
				fac[j]=i;
				j++;
				sumi+=i;
			}
		}
		if(sumi==t){
			printf("%d=%d",t,fac[0]);
			for(k=1;k<j;k++){
				printf("+%d",fac[k]);
			}
			printf("\n");
		}
		sumi=0;
	}
	return 0;
}
