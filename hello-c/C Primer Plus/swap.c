#include <stdio.h>
void swap(int a,int b)
{
    printf("address in swap():%p %p\n",&a,&b);
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=4,b=5;
    printf("address in main():%p %p\n",&a,&b);
    swap(a,b);
    printf("a = %d ,b = %d\n",a,b);
    return 0;
}