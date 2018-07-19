#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[]){
    float x1,y1,x2,y2,x_dis,y_dis;
    while(scanf("%f %f %f %f",&x1,&y1,&x2,&y2)!=EOF){
        getchar();
        x_dis=x1-x2;
        y_dis=y1-y2;
        printf("%.2f\n",sqrt(y_dis*y_dis+x_dis*x_dis));
    }

    return 0;
}
