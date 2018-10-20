#include<stdio.h>
int main(){
    int sco[100],i=0,n[100],j;
    while(scanf("%d",&sco[i])!=EOF){
        
        printf("%d",sco[i]);
        i++;
    }
    for(j=0;j<=i;j++){
        n[i]=sco[i]/10;
        printf("%d",n[i]);
    }
    for(j=0;j<=i;j++){
        if(n[i]<0||n[i]>10){
            printf("Score is error!\n");
            continue;
        }
        switch(n[i]){

            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:printf("E\n");break;
            case 6:printf("D\n");break;
            case 7:printf("C\n");break;
            case 8:printf("B\n");break;
            case 9:
            case 10:printf("A\n");break;
        }
        i++;
    }
    return 0;
}
