#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    int c,q=1;
    while((c=getchar())!=EOF){
        if(c=='"'){
            printf("%s",q?"``":"''");
            q=!q;//=!为反转真假的运算符
        }
        else{
            printf("%c",c);
        }
    }
    return 0;
}
