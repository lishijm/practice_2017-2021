#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,tmp;
	scanf("%d\n",&n);
	int mark[n],stu[n];
	for(i=0;i<n;i++){
		scanf("%d",&mark[i]);
		stu[i]=i+1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<n;j++){
			if(mark[j]<mark[j+1]){
				tmp=mark[j+1];
				mark[j+1]=mark[j];
				mark[j]=tmp;
				tmp=stu[j+1];
				stu[j+1]=stu[j];
				stu[j]=tmp;
			}
		}
	}
	j=1;
	for(i=0;i<n;i++){
		printf("%d:%d,%d\n",j,stu[i],mark[i]);
		if(i<n-1){
			if(mark[i+1]<mark[i]){
				j++;
			}
		}
	}
	return 0;
}
