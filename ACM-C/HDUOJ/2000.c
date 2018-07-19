#include<stdio.h>
int main(){
    char word[3],tmp;
    int i,j;
    while(scanf("%c%c%c",&word[0],&word[1],&word[2])!=EOF){
        getchar();
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                if(word[j]>=word[j+1]){
                    tmp=word[j];
                    word[j]=word[j+1];
                    word[j+1]=tmp;
                }
            }
        }
        printf("%c %c %c\n",word[0],word[1],word[2]);
    }
    
    return 0;
}
