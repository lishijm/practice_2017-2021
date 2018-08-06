#include<stdio.h>
int fac();

int fac(int n){
	int fac=1,i;
	for(i=n;i>0;i--){
		fac*=i;
	}
	return fac;
}
int main(){
    int m,n,tmp;
    scanf("%d %d",&m,&n);
    if(m>n){
        tmp=m;
        m=n;
        n=tmp;
    }
    printf("%d %d",fac(n)/fac(n-m),fac(n)/(fac(m)*fac(n-m)));

    return 0;
}
