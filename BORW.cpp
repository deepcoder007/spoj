#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

inline int scan()
{
  register int n=0;
  int sgn=1;  
  register char c;
  c=getchar_unlocked();
  while( (c<'0' || c>'9') && c!='-' )
    c=getchar_unlocked();
  if( c=='-' )
    {
      sgn=-1;
      c=getchar_unlocked();
    }
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n*sgn;
}

int arr[210];
int dp[210][210][210];
int n;

int main()
{
  register int i,j,k;
  while(1)
    {
      n=scan();
      if( n==-1 )
	break;
      for(i=1;i<=n;i++)
	arr[i]=scan();
      memset(dp,0,sizeof(dp));

      for(i=1;i<=n;i++)
	{
	  for(j=i+1;j<=(n+1);j++)
	    {
	      for(k=i+1;k<=(n+1);k++)
		{
		  dp[i][j][k]=dp[i-1][j][k]+1;

		  if( j>n || arr[i]<arr[j] )
		    dp[i][j][k]=min(dp[i][j][k],dp[i-1][i][k]);

		  if( k>n || arr[i]>arr[k] )
		    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][i]);

		}
	    }
	}
      printf("%d\n",dp[n][n+1][n+1]);
    }
  return 0;
}
