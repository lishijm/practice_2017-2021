#include <stdio.h> 
#include <stdlib.h> 
int main(){	
	int M,i,j,n,num=1; 
	int a[20][20]; 
	scanf("%d",&M); 
	for(n=0;n<=M/2;n++){
		for(j=n;j<=M-n-1;j++){
			a[n][j]=num++; 
		}
		for(i=n+1;i<M-n-1;i++){
			a[i][M-n-1]=num++; 
		}
		for(j=M-n-1;j>n;j--){
			a[M-n-1][j]=num++; 
		}
		for(i=M-n-1;i>n;i--){
			a[i][n]=num++; 
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<M-1;j++){
			printf("%3d ",a[i][j]);
		}
		if(j==M-1){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
