#include <stdio.h>
#include <math.h>
int main()
{
  int a,b;
  int i,j,k;
  int num=0,s;
  scanf("%d %d",&a,&b);
  for(i=a;i+2<=b;i++)
  {
      s = 1;
      k = sqrt(i);
      for(j=2;j<=k;j++)
      {
          if(i%j==0)
          {
              s = 0;
              break;
          }
      }
      if( s )
      {
          k = sqrt(i+2);
          for(j=2;j<=k;j++)
          {
              if((i+2)%j == 0)
              {
                  s = 0;
                  break;
              }
          }
          if(s)
          {
              ++num;
              printf("(%d,%d)",i,i+2);
          }
      }
  }
  return 0;
}
