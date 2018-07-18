#include<stdio.h>
#include<math.h>
int cap(int x,int n){
	int i,cap=1;
	for(i=1;i<=n;i++){
		cap=cap*x;
	}
	return cap;
}
int main(){
	int x,n;
	scanf("%d %d",&x,&n);
	printf("%d",cap(x,n));
	
	return 0;
}
