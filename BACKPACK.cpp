#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
// use a DFS/BFS based approach to find arbitrage

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

inline int max(int i,int j)
{
  if( i>j ) return i;
  else return j;
}

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while(c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int dp[70][33000];   // weights are the multiple of 10
int c[70];
int w[70];
int v[70];
int u[70];  // the dependency
int tmp1,tmp2,tmp3;
int flag[70];  // to flag if the object is used earlier or not

inline void test()
{
  int V,n;
  V=scan();n=scan();
  register int i,j;
  for( i=1 ; i<=n ; i++ )
    {
      w[i]=scan(); c[i]=scan();  u[i]=scan();
      v[i]=w[i]*c[i];
    }
  memset(dp,0,sizeof(dp));
  memset(flag,0,sizeof(flag)); // flag=1 means that the object is used   

  for( i=1;i<=V; i++ )
    dp[0][i]=0;

  for( i=1; i<=n; i++)
    {
      if( u[i]!=0 && flag[u[i]]==0 )  // i.e. it is having a parent
	{
	  w[i]+=w[u[i]];
	}
      for( j=1 ; j<=V ; j++ )
	{
	  if( w[i]>j )  // i.e. too high weight
	    dp[i][j]=dp[i-1][j];
	  else
	    {
	      dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i] );
	      
	      if(u[i]!=0 && dp[i][j]!=dp[i-1][j] )
		flag[u[i]]=1;
	    }
	}
    }
  printf("%d\n",dp[n][V]);

}

int main()
{
  int t=scan();
  while(t--)
    test();
  return 0;
}
