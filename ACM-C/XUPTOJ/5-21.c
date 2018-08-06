#include<stdio.h>
int main(){
	int a,b,c,x,y,z,t,n,i,j,k,zhongjian;
	scanf("%d %d %d",&a,&b,&c);
	x=a;y=b;z=c;
	
	if(x<y){
		zhongjian=x;
		x=y;
		y=zhongjian;
	}
	while(y!=0){
		i=x%y;
		x=y;
		y=i;
	}
	t=(a*b)/x;
	//第二部分 
	j=t;
	if(j<z){
		zhongjian=j;
		j=z;
		z=zhongjian;
	}
		while(z!=0){
		k=j%z;
		j=z;
		z=k;
	}
	n=(t*c)/j;
	
	printf("%d",n);

	return 0;
}
