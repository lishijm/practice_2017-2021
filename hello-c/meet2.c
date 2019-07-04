#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[7],i,j;
    for(i=0;i<7;i++){
        scanf("%d",&a[i]);
    }
    int num=0,mark;
    for(i=0;i<7;i++){
        for(j=i;j<7;j++){
            if(a[j+1]==a[i]){
                num++;
                mark=a[i];
            }
        }
        if(num>3){
            printf("%d",mark);
            break;
        }
        num=0;
    }
    return 0;
}
