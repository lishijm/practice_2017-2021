#include<stdio.h>
#include<math.h>
int main(){
	int n,i;
	float x_1,x_2,y_1,y_2;
	scanf("%d\n",&n);
	float dis[n];
	for(i=0;i<n;i++){
		scanf("%f %f %f %f",&x_1,&y_1,&x_2,&y_2);
		dis[i]=sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
	}
	for(i=0;i<n;i++){
		printf("%.2f\n",dis[i]);
	}
	return 0;
}
