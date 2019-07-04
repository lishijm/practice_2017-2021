//指针操作
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int urn[5]={100,200,300,400,500};
    int *p1,*p2,*p3;
    
    p1=urn;
    p2=&urn[2];

    printf("p1=%p *p1=%d &p1=%p\n",p1,*p1,&p1);

    //加法
    p3=p1+4;
    printf("p1+4=%p *(p1+4)=%d\n",p1+4,*(p1+4));
    //指针递增
    p1++;
    printf("p1=%p *p1=%d &p1=%p\n",p1,*p1,&p1);
    //指针递减
    p2--;
    printf("p2=%p *p2=%d &p2=%p\n",p2,*p2,&p2);
    --p1;++p2;
    printf("p1=%p p2=%p\n",p1,p2);
    //一个指针减去另一个指针
    printf("p1=%p p2=%p p2-p1=%d\n",p1,p2,p2-p1);
    //一个指针减去一个整数
    printf("p3=%p p3-2=%p\n",p3,p3-2);

    return 0;
}
