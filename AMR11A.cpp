#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

inline int max(int i,int j)
{
  if( i<j ) return j;
  else return i;
}

inline int min(int i,int j)
{
  if( i>j ) return j;
  else return i;
}

inline int scan()
{
  register int neg=1;
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while( (c<'0' || c>'9') && c!='-' )
    c=getchar_unlocked();
  if(c=='-')
    {
      neg=-1;
      c=getchar_unlocked();
    }
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n*neg;
}

int t,r,c;
int S[510][510]; 
int dp[510][510];
//int dir[510][510]; // to store the directions
int minima[510][510];  // to store the minima on the path-> including current

void test()
{
  r=scan(); c=scan();
  register int i,j;
  memset(S,0,sizeof(int)*510*510);
  memset(dp,0,sizeof(int)*510*510);
  //  memset(dir,0,sizeof(int)*510*510);
  for(i=1;i<=r;i++)
      for(j=1;j<=c;j++)
	  S[i][j]=scan();
  int mp=1;  // the minimum power-> this is the offset for ever cell
  //  int cp=1;  // the current power
  dp[1][1]=1;   // power on the first cell assumed
  minima[1][1]=1;  // the minimum power uptil now
  for(i=2;i<=c;i++)
    {
      // dir[1][i]=1;  // right
      dp[1][i]=dp[1][i-1]+S[1][i];
      minima[1][i]=min(minima[1][i-1],dp[1][i]);
    }
  for(i=2;i<=r;i++)
    {
      // dir[i][1]=-1;  //down
      dp[i][1]=dp[i-1][1]+S[i][1];
      minima[i][1]=min(minima[i-1][1],dp[i][1]);
    }
  for(i=2;i<=r;i++)
      for(j=2;j<=c;j++)
	{
	  //  dp[i][j]=max(dp[i-1][j],dp[i][j-1])+S[i][j];
	  if(minima[i-1][j]>minima[i][j-1]) 
	    {
	      dp[i][j]=dp[i-1][j]+S[i][j];
	      minima[i][j]=min(minima[i-1][j],dp[i][j]);
	      //      dir[i][j]=-1;
	    }
	  else
	    {
	      dp[i][j]=dp[i][j-1]+S[i][j];
	      minima[i][j]=min(minima[i][j-1],dp[i][j]);
	      //  dir[i][j]=1;
	    }
	}
  if( minima[r][c]<=0 )
    cout<<2-minima[r][c]<<endl;
  else
    cout<<1<<endl;
}


int main()
{
  t=scan();
  while(t--)
    test();
  return 0;
}
