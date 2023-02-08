#include<stdio.h>  
  
const    int COUNT= 11;  
main()  
{  
    int arr[]={10,8,9,3,2,4,7,6,5,1,0};  
    int i,j;  
    for(j=0;j<COUNT-1;j++){  
        for(i=0;i<COUNT-1-j;i++){  
  
                if (arr[i]>arr[i+1]){  
                    int tmp=arr[i]; arr[i]=arr[i+1];arr[i+1]=tmp;  
                }  
  
        }  
        for(i=0;i<COUNT;i++){  
            printf("%d,",arr[i]);  
  
  
        }  
    printf("\n loop(%d):================\n",j);  
  
    }  
    for(i=0;i<COUNT;i++){  
        printf("%d,",arr[i]);  
    }  
    printf("over");  
}  
