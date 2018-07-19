#include<stdio.h>
int pfc(int x){
	int i=1,s=0;//yÊÇÒòÊı
	for(i=1;i<x;i++){
		if(x%i==0)
            s=i+s;
    }
    if(s==x){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int x,i,flag;
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        flag=pfc(i);
        if(flag==1){
            printf("%d ",i);
        }
    }
    return 0;
}
