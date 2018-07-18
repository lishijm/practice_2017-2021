#include<stdio.h>
#include<string.h>
int main(){
	int n,num=0,i,j;
	scanf("%d",&n);
	char word[20],ch;
	for(i=0;i<n;i++){
		num=0;
		scanf("%s %c",&word,&ch);
		for(j=0;j<20;j++){
			if(word[j]=='\0'){
				break;
			}
			if(ch==word[j]){
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
