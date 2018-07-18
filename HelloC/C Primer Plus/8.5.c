#include<stdio.h>
int main(){
	int ch;
	int rows,cols;
	while((ch=getchar())!='n'){
		scanf("%d %d",&rows,&cols);
		display(ch,rows,cols);
	}
	return 0;
}
void display(char cr,int lines,int width){
	int row col;
	
	for(row=1;row<=lines;row++){
		for(col=1;col<=width;col++){
			putchar(cr);
		}
		putchar('\n');
	}
}
