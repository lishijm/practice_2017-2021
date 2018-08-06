#include<stdio.h>
#include<Windows.h>
#include<string.h>
int main()
{ 
    char filepath[1000], batpath[1010]; //the absolute path of a file folder and a .bat file.
    gets(filepath);//input absolute path of a file folder
    strcpy(batpath, filepath);
    strcat(batpath, "\\Text1.bat");
    FILE *fp;
    fp = fopen(batpath, "w");
    fputs("DIR *.c /B>list.txt", fp);
    fclose(fp);
    system(batpath); 
    /*~~~the end of creating file name list~~~*/
    
    /*~~~the beginning of get .c file name from list~~~*/
    static int count = 0; 
    FILE *fp1, *fp2;
    fp1 = fopen("list.txt", "r");
    char s[100];
    char singleline[1000];
    while(fgets(s, 100, fp1))//get one line from list, each line refers to a .c file name
    {
        int len = strlen(s);
        if(s[len-1] == '\n') s[len-1] = '\0';
        printf("%s: ", s);  
        fp2 = fopen(s, "r");
        
        /*~~~the beginning of counting lines of code~~~*/
        
        while(fgets(singleline, 1000, fp2))//open the correct file, according to the file name
        {
            count++;
        }   
        printf("%d\n", count);
        fclose(fp2);
    }
    printf("\n");
    fclose(fp1);
    
    system("pause");
    return 0;
}  