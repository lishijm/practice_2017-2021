#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,flag=0,k;
	scanf("%d\n",&n);
	char word_1[21],word_2[21],word_e[10][21];
	for(i=0;i<n;i++){
		flag=0;
		k=0;
		scanf("%s %s",&word_1,&word_2);
		for(j=0;j<20;j++){
			if(word_1[j]=='\0'||word_2[j]=='\0'){
				break;
			}
			if(word_1[j]==word_2[j]){
				if(j!=0&&flag==0){
					break;
				}
				else{
					flag=1;
					word_e[i][j]=word_1[j];
					k++;
				}
			}
		}
		if(flag==0){
			printf("无公共前缀\n");
		}
		else{
			for(j=0;j<k-1;j++){
				printf("%c",word_e[i][j]);
			}
			if(j==k-1){
				printf("%c\n",word_e[i][j]);
			}
		}
	}
	return 0;
}
