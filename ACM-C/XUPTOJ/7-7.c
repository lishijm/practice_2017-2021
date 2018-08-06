#include<stdio.h>
int main(){
	int n,m,tmp,i,j,k,t,flag=0;
	scanf("%d\n",&n);
	int num_s[n];
	for(i=0;i<n;i++){
		scanf("%d",&num_s[i]);
	}
	scanf("%d",&m);
	int num_i[m];
	for(i=0;i<m;i++){
		scanf("%d",&num_i[i]);
	}
	//插入元素之后元素往后顺位 
	for(j=0;j<m;j++){
		for(i=0;i<n+j;i++){
			if(num_i[j]<num_s[i]){
				for(k=n+j;k>=i;k--){
					num_s[k+1]=num_s[k];
				}
				num_s[i]=num_i[j];
				break;
			}
			if(num_i[j]>=num_s[n+j-1]){
				num_s[n+j]=num_i[j];
				break;
			}
		}
		for(t=0;t<n+j;t++){
			printf("%d ",num_s[t]);
		}
		printf("%d\n",num_s[n+j]);
		flag=0;
	}
	return 0;
}
