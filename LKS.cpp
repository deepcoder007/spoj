#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

inline int max(int i,int j)
{
  if( i>j ) return i;
  else return j;
}

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

int k,n; 
int v[510];
int w[510];

int dp[502][2000002];

int main()
{
  cin>>k>>n;
  register int i,j;
  for(i=0;i<n;i++)
    cin>>v[i]>>w[i];

  // start the dp
  for(i=0;i<=k;i++)
    dp[0][i]=0;
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=k;j++)
	{
	  if( w[i-1]>j )
	    {
	      dp[i][j]=dp[i-1][j];
	    }
	  else
	    {
	      dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
	    }
	}
    }
  /**
  cout<<"the dp matrix: "<<endl;
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=k;j++)
	{
	  cout<<dp[i][j]<<" ";
	}
      cout<<endl;
    }
  **/
  cout<<dp[n][k]<<endl;
}
