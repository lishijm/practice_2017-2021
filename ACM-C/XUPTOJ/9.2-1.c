#include<stdio.h>
struct date{
    int year,month,day;
};
struct book{
    int id;
    char name[30];
    char aut[30];
    char pub[30];
    struct date dates;
    float pri;
};
int main(int argc, char const *argv[])
{
    struct book books;
    scanf("%d %s %s %s %d-%d-%d %f",&books.id,&books.name,&books.aut,&books.pub,&books.dates.year,&books.dates.month,&books.dates.day,&books.pri);
    printf("??:%d\n??:%s\n??:%s\n???:%s\n????:%d?%d?%d?\n??:%f",books.id,books.name,books.aut,books.pub,books.dates.year,books.dates.month,books.dates.day,books.pri);
    return 0;
}
