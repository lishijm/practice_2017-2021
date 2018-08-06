#include<stdio.h>
int main(){
    int m,i,j,t=2,num,n=0,flag=0;
    scanf("%d\n",&m);
    int num_s[m];
    int fac[10];
    for(i=0;i<m;i++){
        scanf("%d",&num_s[i]);
    }
    for(i=0;i<m;i++){
        n=0;
        num=num_s[i];
        if(num<=2){
        	if(num==2){
        		printf("%d是质数\n",num_s[i]);
			}
		}
		else{
			t=2;
			while(num>=t){
            	if(num%t==0){
                	fac[n]=t;
                	num=num/t;
                	t=2;
                	n++;
                	flag=1;
            	}
            	else{
                	t++;
                	if(t==num_s[i]){
                    	t=num_s[i]+1;
                	}
            	}
        	}
        	if(flag==1){
            	printf("%d=%d",num_s[i],fac[0]);
            	for(j=1;j<n;j++){
                	printf("*%d",fac[j]);
            	}
            	printf("\n");
        	}
        	if(flag==0){
            	printf("%d是质数\n",num_s[i]);
        	}
        	flag=0;
		}
    }
    return 0;
}
