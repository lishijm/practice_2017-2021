#include <stdio.h>
int main (void)
{
	printf("Pleas input inch.\n");
	
    float inch;
    float cm;
    
    scanf("%f", &inch);
	cm=2.54*inch;
	
	printf("It is %.2f cm.",cm,inch);
	
	return 0;
}
