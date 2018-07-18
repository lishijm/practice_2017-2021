#include<stdio.h>
int main(){
	int m,n,i,j=0,k=0,flag=0;
	scanf("%d %d\n",&m,&n);
	int num_1[m],num_2[n],num_e[m+n];
	for(i=0;i<m;i++){
		scanf("%d",&num_1[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&num_2[i]);
	}
	for(i=0;i<m+n;i++){
		if(flag==0){
			if(num_1[j]<num_2[k]){
				num_e[i]=num_1[j];
				j++;
				if(j==m){
					flag=1;
				}
			}
			else{
				num_e[i]=num_2[k];
				k++;
				if(k==n){
					flag=2;
				}
			}
		}
		if(flag==2){
			num_e[i+1]=num_1[j];
			j++;
		}
		if(flag==1){
			num_e[i+1]=num_2[k];
			k++;
		}
	}
	for(i=0;i<n+m-1;i++){
		printf("%d ",num_e[i]);
	}
	printf("%d",num_e[n+m-1]);
	
	return 0;
}
