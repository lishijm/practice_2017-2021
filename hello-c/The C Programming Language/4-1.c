#include<stdio.h>
#define MAXLINE 1000

char pattern[]="ould";

int getline(char s[],int lim){
    int c,i;
    i=0;
    while(--lim>0&&(c=getchar())!=EOF&&c!='\n'){
        s[i++]=c;
    }
    if(c=='\n'){
        s[i++]=c;
    }
    s[i]='\0';
    return i;
}

int sttrindex(char s[],char t[],int num){
    int i,j,k;
    for(i=0;s[i]>'\0';i++){
        for(j=1,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++){
            ;
        }   
        if(t[k]=='\0'){
            return i;
        }
        else{
            return -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found=0;
    int num;
    while(getline(line,MAXLINE)>0){
        num=getline(line,MAXLINE);
        if(sttrindex(line,pattern,num)>=0){
            printf("%s",line);
            found++;
        }
    }
    return found;
}
