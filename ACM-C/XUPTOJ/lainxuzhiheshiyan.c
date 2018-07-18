#include <stdio.h>
int main()
{
    int row,i,j,N ;
    scanf("%d", &N ); //输入大小
    row=1;
    while(row<=N)   /*前N排星号*/
    {
        for(i=1;i<=N-row;i++)
            printf(" ");
        for(j=1;j<=2*row-1;j++)
            printf("*");
        printf("\n");
        row++;
    }
    row=1;
     
    while(row<=N-1)   /*后N-1排星号*/
    {
        for(i=1;i<=row;i++)
            printf(" ");
        for(j=1;j<=2*(N-row)-1;j++)
            printf("*");
        printf("\n");
        row++;
    }
     
    return 0;
}
