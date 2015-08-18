#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

inline long long max(long long i,long long j)
{
  if( i>j ) return i;
  else return j;
}

inline long long min(long long i,long long j)
{
  if( i<j ) return i;
  else return j;
}

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while( c<'0' || c>'9' )
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

long long ye[510][510];
long long bl[510][510]; 
long long dp[510][510];

int main()
{
  int n,m;
  register int i,j,k,l;
  long long tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
  while(1)
    {
      n=scan();  m=scan();
      if( n==0 && m==0 ) return 0;
      for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	  ye[i][j]=scan();
      for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	  bl[i][j]=scan();
      memset(dp,0,sizeof(dp));
      // initialize base case
      tmp1=0;     // the bl of the last row
      for( i=0;i<m;i++ )
	tmp1+=bl[n-1][i];  
      tmp2=0;
      // now init the last row of dp
      for(i=0;i<m;i++)
	{
	  dp[n-1][i]=tmp1+tmp2;
	  tmp1-=bl[n-1][i];
	  tmp2+=ye[n-1][i];
	}
      dp[n-1][m]=tmp1+tmp2;     // DON'T ever forget this last case
      // now init the other rows of the dp
      for( i=n-2 ; i>=0; i-- )
	{
	  tmp1=0;
	  for(j=0;j<m;j++)
	    tmp1+=bl[i][j];
	  tmp2=0;
	  for(j=0;j<m;j++)
	    {
	      dp[i][j]=tmp1+tmp2;
	      tmp1-=bl[i][j];
	      tmp2+=ye[i][j];
	      // now consider the row below it
	      tmp3=0;
	      for(k=j;k<=m;k++)   // consider all the scenarios below it
		{
		  tmp3=max(tmp3,dp[i+1][k]);
		}
	      dp[i][j]+=tmp3;
	    }
	  dp[i][m]=tmp1+tmp2;
	  dp[i][m]+=dp[i+1][m];
	}
      tmp1=0;
      for(i=0;i<=m;i++)
	tmp1=max(tmp1,dp[0][i]);
      cout<<tmp1<<endl;
    }
  return 0;
}
