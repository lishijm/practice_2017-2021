#include<stdio.h>
int main(){
    int i,j,st;
    scanf("%d",&st);
    float tmp,mark[st],sum=0.0,max,min;
    for(i=0;i<st;i++){
        scanf("%f",&mark[i]);
        sum+=mark[i];
    }
    max=mark[0];min=mark[0];
    for(i=0;i<st;i++){
        if(max<=mark[i]){
            max=mark[i];
        }
        if(min>=mark[i]){
            min=mark[i];
        }
    }
    printf("%.2f %.2f %.2f\n",sum/10,max,min);
    for(i=1;i<st;i++){
		for(j=0;j<st;j++){
			if(mark[j]<mark[j+1]){
				tmp=mark[j+1];
				mark[j+1]=mark[j];
				mark[j]=tmp;
            }
		}
    }
    for(i=0;i<st;i++){
        printf("%.2f ",mark[i]);
    }
    return 0;
}
