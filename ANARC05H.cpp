#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[30];  // to hold the input string
int dp[40][235];   

int get_c(int s,int l) // get the no. of combinations given the last post to consider and the ceil i.e. sum
{
  int i;
  if( l<0 ) return 1;   // i.e. out of bound
  int count =0 ;
  int sum = 0 ;
  for( i = l ; i>=0 ; i-- )
    {
      sum += ( str[i] - '0' );
      if( sum <=s )  // i.e. within bound 
	{
	  count+=get_c(sum,i-1);
	}
    }
  return count;
}

int main()
{
  int i=0;
  while(1)
    {
      scanf("%s",str);
      if( str[0]=='b' )
	return 0;
      else
	{
	  i++;
	  printf("%d. %d\n",i,get_c(100000,strlen(str)-1));
	}
    }
  return 0;
}
