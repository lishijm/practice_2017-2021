#include<stdio.h>
int main(){
    int t,i;
    char a[13],b[7];
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        b[0]='6';
        for(i=1;i<7;i++)
            b[i]=a[i+5]; 
        printf("%s\n",b);
    }
    return 0;
}
