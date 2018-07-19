#include<stdio.h>
struct birth{
    int year,month,day;
};
struct st{
    int num;
    char name[20];
    char sex[20];
    struct birth birth_1;
};
int main(){
    struct st st_1;
    scanf("%d %s %s %d-%d-%d",&st_1.num,&st_1.name,&st_1.sex,&st_1.birth_1.year,&st_1.birth_1.month,&st_1.birth_1.day);
    printf("%d %s %s %d-%d-%d",st_1.num,st_1.name,st_1.sex,st_1.birth_1.year,st_1.birth_1.month,st_1.birth_1.day);
    return 0;
}