#include<stdio.h>
int main(){
	int n,flag_1=0,flag_2=0,i,j,k,m,re,x;
	scanf("%d",&n);
	int num[n];
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++){
		for(j=2;j<num[i];j++){
			if(num[i]%j==0){
				flag_1=1;
				break;
			}
		}
		k=0;
		m=num[i];
		re=0;
		while(m!=0){
			x=m%10;
			m=m/10;
			re=re*10+x;
		}
		for(j=2;j<re;j++){
			if(re%j==0){
				flag_2=1;
				break;
			}
		}
		if(flag_1==0&&flag_2==0){
			printf("%d是可逆素数\n",num[i]);
		}
		if(flag_1==0&&flag_2==1){
			printf("%d是素数，但不是可逆素数\n",num[i]);
		}
		if(flag_1==1&&flag_2==1){
			printf("%d不是素数\n",num[i]);
		}
		flag_1=0;flag_2=0;
	}
	return 0;
} 
