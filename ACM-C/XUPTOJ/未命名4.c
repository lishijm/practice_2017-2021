#include<stdio.h>
int main(){
	int x,y,t,a,b,c,d;
	scanf("%d %d",&x,&y);
	for(t=x;t<=y;t++){
		a=t/1000;
		b=(t/100)%10;
		c=(t%100)/10;
		d=t%10;
		if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==t){
			printf("%d%d%d%d\n",a,b,c,d);
		}
	}
	return 0;
}
