#include <stdio.h>
#include <math.h>
#define PI 3.14 
int main(){
	float r;
	double c,s;
	
	scanf("%f",&r);
	c=2*PI*r;
	s=PI*r*r;
	printf("%f %f",c,s);
	
	return 0;
}
