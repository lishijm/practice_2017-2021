#include<stdio.h>
struct st{
    int num;
    float mark;
    char name[20];
};
int main(){
    struct st sts[2];
    int i;
    for(i=0;i<2;i++){
        scanf("%d %s %f",&sts[i].num,&sts[i].name,&sts[i].mark);
    }
    if(sts[0].mark>sts[1].mark){
        printf("%d %s %f",sts[0].num,sts[0].name,sts[0].mark);
    }
    else{
        printf("%d %s %.2f",sts[1].num,sts[1].name,sts[1].mark);
    } 
    return 0;
}
