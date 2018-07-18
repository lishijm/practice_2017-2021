#include<stdio.h>
#include<string.h>
struct date{
    int year,month,day;
};
struct book{
    int num;
    float pri;
    char name[30],wter[30],pub[30];
    struct date dates;
};
int main(){
    int n,i,j;
    char name_del[30];
    struct book books[20];
    struct book tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %s %s %s %4d-%2d-%2d %f",&books[i].num,&books[i].name,&books[i].wter,&books[i].pub,&books[i].dates.year,&books[i].dates.month,&books[i].dates.day,&books[i].pri);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(books[j].pri>=books[j+1].pri){
                tmp=books[j];
                books[j]=books[j+1];
                books[j+1]=tmp;
            }
        }
    }
    printf("编号 书名 作者 出版社 出版日期 价格\n");
    for(i=0;i<n;i++){
        printf("%d %s %s %s %d年%d月%d日 %.2f\n",books[i].num,books[i].name,books[i].wter,&books[i].pub,books[i].dates.year,books[i].dates.month,books[i].dates.day,books[i].pri);        
    }
    return 0;
}
