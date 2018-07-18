//two_func.c -- 一个文件中包含两个函数实验 
#include <stdio.h>
void butler (void); //ANSI/ISO C函数原型  "butler " 可随意定义 
int main (void)
{
	printf("I will summon the butler function\n");
    butler();
	printf("Yes,bring me some tea and writeable DVDs.\n");
	
	getchar();
	
	return 0;
}
void butler (void) //函数定义的开始 
{
	printf("You rang,sir?\n");
}

