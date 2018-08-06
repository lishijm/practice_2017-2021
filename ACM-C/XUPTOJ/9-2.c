#include<stdio.h>
struct sts{
    int mark[5];
};
int main(){
    int sum_1[5]={0,0,0,0,0},sum_2[10]={0,0,0,0,0,0,0,0,0,0},max,i,j,g,h;
    struct sts st[10];
    for(i=0;i<10;i++){
        for(j=0;j<5;j++){
            scanf("%d",&st[i].mark[j]);
            sum_2[i]+=st[i].mark[j];
        }
        printf("%d ",sum_2[i]/5);
    }
    for(j=0;j<5;j++){
        for(i=0;i<10;i++){
            sum_1[j]+=st[i].mark[j];
        }
        printf("%d ",sum_1[j]);
    }
    max=st[0].mark[0];
    for(i=0;i<10;i++){
        for(j=0;j<5;j++){
            if(max<=st[i].mark[i]){
                max=st[i].mark[j];
                g=i;
                h=j;
            }
        }
    }
    printf("%d %d",g,h);

    return 0;
}