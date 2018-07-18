#include<stdio.h>   
#include<math.h>    
int main()      
{   
    int x,y,n,k,i;  
    scanf("%d %d",&x,&y);  
    
	if(x==1)  
    y=2;  
    
	for(n=x;n<=y;n++)   
    {
	    k=sqrt(n);
        for(i=2;i<=k;i++)
        
		if(n%i==0)
		break;  
        
		if(i>=k+1)
        {
        	printf("%d ",n);
		} 
	}
    return 0;  
}  
