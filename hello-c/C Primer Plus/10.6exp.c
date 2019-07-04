#include<stdio.h>
#include<stdlib.h>
int sum(const int ar[],int n){
    int i;
    int total=0;
    for(i=0;i<n;i++){
        total+=ar[i];
    }
    return total;
}
int main(int argc, char const *argv[])
{
    int sums,n=10,ar[10]={1,2,3,4,5,6,7,8,9,10};
    sums=sum(ar,n);
    printf("%d",sums);
    return 0;
}
