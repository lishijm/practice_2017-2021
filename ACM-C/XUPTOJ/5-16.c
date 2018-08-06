#include<stdio.h>
int main(){
	int s,i,sum,N;//s为开始的年龄，i为计数君，sum为和
	scanf("%d",&N);
	
	for(s=1;s<=N;s++){
		for(i=1;i<=N;i++){
			sum=(i*(s+s+(i-1)))/2;
			if(sum==N){
				printf("%d %d",s,s+(i-1));
				
				s=N+1;
				i=N+1;
			}
		}
	}
	return 0;
}
