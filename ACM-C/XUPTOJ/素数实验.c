#include<stdio.h>
main()
{
  int a,b,x,q;
  int flog=1;
  scanf("%d%d",&a,&b);
    if(a<=2&&b>=2)
    printf("2");          
			for(x=3;x<=b;x++)
            {
             flog=1;
              for(q=2;q<x;q++) 
              {
                 if(x%q==0)
                  {
                  flog=0;
                  break;
                  }
              }
              
            if(flog==1)
            printf(" %d",x);

            }
}  
