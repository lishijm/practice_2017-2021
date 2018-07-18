#include<stdio.h> 
int main(int argc, char const *argv[])
{
    int sco,n;
    while(scanf("%d",&sco)!=EOF){
        getchar();
        n=sco/10;
        if(n<0||n>10){
            printf("Score is error!\n");
            continue;
        }
        switch(n){
            case 0:printf("E\n");break;
            case 1:printf("E\n");break;
            case 2:printf("E\n");break;
            case 3:printf("E\n");break;
            case 4:printf("E\n");break;
            case 5:printf("E\n");break;
            case 6:printf("D\n");break;
            case 7:printf("C\n");break;
            case 8:printf("B\n");break;
            case 9:printf("A\n");break;
            case 10:printf("A\n");break;
        }
    }
    return 0;
}
