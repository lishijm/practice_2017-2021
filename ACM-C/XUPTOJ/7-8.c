#include<stdio.h>
int main(){
	int m,n,i,j;
	scanf("%d %d\n",&m,&n);
	int num[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j<m-1){
				printf("%d ",num[j][i]);
			}
			else{
				printf("%d",num[j][i]);
			}
		}
		printf("\n");
	}
	return 0;
} 
