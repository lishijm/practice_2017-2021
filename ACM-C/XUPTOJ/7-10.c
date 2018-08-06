#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int n,i,j,max,num_i,num_j,tmp,num_s;
	scanf("%d\n",&n);
	int num[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(j=0;j<n;j++){
		if(num[0][j]<0){
			max=-num[0][j];
		}
		else{
			max=num[0][j];
		}
		for(i=1;i<n;i++){
			if(num[i][j]<0){
				num_s=-num[i][j];
				if(max<num_s){
					max=num[i][j];
					num_i=i; 
				}
			}
			else{
				if(max<num[i][j]){
					max=num[i][j];
					num_i=i; 
				}
			}	
		}
		tmp=num[num_i][num_i];
		num[num_i][num_i]=num[num_i][j];
		num[num_i][j]=tmp;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			printf("%3d ",num[i][j]);
		}
		if(j==n-1){
			printf("%3d\n",num[i][j]);
		}
	}
	return 0;
} 
