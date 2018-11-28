#include<stdio.h>
#include <iostream.h>
using namespace std;
int main()
{
	static int a[1000];
	int m,n,i,j;
	cin>>m>>n;
	for(i=2;i<=n;i++)
		for(j=1;j<=m;j++)
			if(j%i==0) a[j]=a[j]^1;
	for(i=1;i<=m;i++)
		if(a[i]==0) cout<<i<<" ";
	return 0;
}