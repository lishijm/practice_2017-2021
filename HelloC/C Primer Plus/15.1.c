#include<stdio.h>
#include<limits.h>
char *itobs(int n, char *ps){
    int i;
    const static int size=CHAR_BIT*sizeof(int);

    for (i=size-1;i>=0;i--,n>>=1){
        ps[i]=(01&n)+'0';
    }
    ps[size]='\0';

    return ps;
}
//四位一组显示二进制字符串
void show_bstr(const char *str){
    int i=0;
    
    while(str[i]){
        putchar(str[i]);
        if(++i&4==0&&str[i]){
            putchar(' ');
        }
    }
}
int main(int argc, char const *argv[])
{
    char bin_str[CHAR_BIT*sizeof(int)+1];
    int number;

    puts("...");
    puts("...");
    while(scanf("%d",&number)==1){
        itobs(number,bin_str);
        printf("%d is",number);
        show_bstr(bin_str);
        putchar('\n'); 
    }
    puts("Bye!");
    return 0;
}
