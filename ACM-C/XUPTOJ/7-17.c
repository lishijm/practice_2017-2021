#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,k,t,v,tmp,nump,rem,car,flag;//rem为余数，car为进位 
	scanf("%d",&n);
	char num[2][50];
	for(i=0;i<n;i++){
		scanf("%s%s",&num[0],&num[1]);//获取数据 
		//数据右移 ，两数组分别执行一次 
		for(j=0;j<2;j++){
			t=0;
			tmp=strlen(num[j]);
			for(k=strlen(num[j])-1;k>=0;k--){ 
				num[j][38-t]=num[j][k]; 
				t++;
			}
			for(v=0;v<=38-tmp;v++){
				num[j][v]='0';
			}
			num[j][39]='\0';
		}
		//数据计算
		j=38;
		car=0;
		while(num[0][j]!=0||num[1][j]!=0){
			nump=num[0][j]+num[1][j]-96;
			rem=nump%10;
			num[0][j]=rem+48;
			if(nump/10==1){
				num[0][j-1]=(num[0][j-1]-48+1)+48;
			}
			j--;
		}
		//输出
		for(k=0;k<38;k++){
			if(num[0][k]!='0'){
				flag=k;
				break;
			}
		} 
		for(v=flag;v<39;v++){
			printf("%c",num[0][v]);
		}
		printf("\n");
	}
	return 0;
} 
