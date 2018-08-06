#include<stdio.h>
int dist(int width,int bd_1,int bd_2){
	int dist,xc,x1,x2,yc,y1,y2,t,i;//xc为横向差 yc为纵向差
	
	if(bd_1%width==0){
		y1=bd_1/width;
	}
	else{
		y1=bd_1/width+1;
	}
	if(bd_2%width==0){
		y2=bd_2/width;
	}
	else{
		y2=bd_2/width+1;
	}
	if(y1<y2){
		t=y1;
		y1=y2;
		y2=t;
		i=bd_1;
		bd_1=bd_2;
		bd_2=i;
	}
	yc=y1-y2;

	if(y1%2==0){
		x1=width-(bd_1%width)+1;
	}
	else{
		x1=bd_1%width;
		if(x1==0){
			x1=width;
		}
	}
	if(y2%2==0){
		x2=width-(bd_2%width)+1;
	}
	else{
		x2=bd_2%width;
		if(x2==0){
			x2=width;
		}
	}
	if(x1<x2){
		t=x1;
		x1=x2;
		x2=t;
	}
	xc=x1-x2;
	dist=xc+yc;
	return dist;
}
int main(){
	int width,bd_1,bd_2,dis;
	scanf("%d %d %d",&width,&bd_1,&bd_2);
	dis=dist(width,bd_1,bd_2);
	printf("%d",dis);
	
	return 0;
}
