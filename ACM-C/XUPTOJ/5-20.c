#include<stdio.h>
int main(){
	int n,sum=0,i,j,s=0;//n为输入的正整数,sum为煤球总数，s为行内和
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			s=s+j;
		}
		sum=s+sum;
		s=0;
	}
	printf("%d",sum); 
	
	return 0;
}
