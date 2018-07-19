#include <stdio.h>
#include <string.h>
typedef struct student
{
	int id;
	char name[20];
	char sex[5];
	int score[3];
	float aver;
}STU;

int Readfile(STU st[])
{
	FILE *fp;
	int i,n;
	fp=fopen("source.txt","r");
	for(i=0; ;i++)
	{
		int x=fscanf(fp,"%d %s %s",&st[i].id,st[i].name,st[i].sex);
		x+=fscanf(fp,"%d %d %d",&st[i].score[0],&st[i].score[1],&st[i].score[2]);
		if(x!=6)
			break;
	}
	n=i;
	fclose(fp);
	return n;
}

void Cal(STU st[],int n)
{
	int i,j,sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
			sum+=st[i].score[j];
		st[i].aver=sum/3.0;
	}
}

void Sort(STU st[],int n)
{
	int i,j;
	STU t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(st[j].aver>st[j+1].aver)
			{
				t=st[j];
				st[j]=st[j+1];
				st[j+1]=t;
			}
		}
	}
}

void Savefile(STU st[],int n)
{
	FILE *fp;
	int i;
	fp=fopen("dest.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%02d %s %s %d %d %d %.2f\n",st[i].id,st[i].name,st[i].sex,st[i].score[0],st[i].score[1],st[i].score[2],st[i].aver);
	}
	fclose(fp);
}

main()
{
	STU st[100];
	int n;
	n=Readfile(st);
	Cal(st,n);
	Sort(st,n);
	Savefile(st,n);
}