#include<stdio.h>
int main()
{
	int num,a=1,b;
	while(a<=9)
	{
		for(b=1;b<=a;b++)
	    {
	    	if(a!=b)
	    	{
	    		if((a*b)/10==0)
	    	    {
	    		    printf("%d*%d= %d  ",b,a,a*b);
			    }
			    else
			    {
				    printf("%d*%d=%d  ",b,a,a*b);
			    }
		    }   
			else//最后一个式子 
			{
				if((a*b)/10==0)
	    	    {  
	    		    printf("%d*%d= %d",b,a,a*b);
			    }
			    else
			    {
				    printf("%d*%d=%d",b,a,a*b);
			    }
			}
		}
		printf("\n");
		a++;
	}
	
	return 0; 
}
