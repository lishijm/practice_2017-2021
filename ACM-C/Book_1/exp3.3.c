//ÉßĞÎÌîÊı
#include<stdio.h>
#include<string.h>
#define maxn 20
int a[maxn][maxn];
int main(int argc, char const *argv[])
{
    int n,x,y,num=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    num=a[x=0][y=n-1]=1;
    while(num<n*n){
        while(x+1<n&&!a[x+1][y]) a[++x][y]=++num;
        while(y-1>=0&&!a[x][y-1]) a[x][--y]=++num;
        while(x-1>=0&&!a[x-1][y]) a[--x][y]=++num;
        while(y+1<n&&!a[x][y+1]) a[x][++y]=++num;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
