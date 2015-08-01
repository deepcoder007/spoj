#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[3000000];  // to store the string

int main()
{
  char curr='0' ;    // the current state
    register int i,j;
    int count =0;
  int n;
  j=1;
  while(scanf("%s",str)==1 ) // while there is input left in the istream
    {
      curr='0';
      count=0;
      n=strlen(str);
      for(i=0;i<n;i++)
	{
	  if( str[i]!=curr)
	    {
	      count++;
	      if( curr=='0')
		curr='1';
	      else
		curr='0';
	    }
	}
      printf("Game #%d: %d\n",j,count);
      j++;
    }
  return 0;
}
      
  
