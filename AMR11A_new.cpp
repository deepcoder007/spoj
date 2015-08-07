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
  S[r][c]=1;
  for(i=r-1;i>0;i--)
    {
      S[i][c]=S[i+1][c]-S[i][c];
      if(S[i][c]<1)
	S[i][c]=1;
    }
  for(i=c-1;i>0;i--)
    {
      S[r][i]=S[r][i+1]-S[r][i];
      if(S[r][i]<1)
	S[r][i]=1;
    }
  for(i=r-1;i>0;i--)
    {
      for(j=c-1;j>0;j--)
	{
	  if( S[i+1][j]<S[i][j+1])
	    S[i][j]=S[i+1][j]-S[i][j];
	  else
	    S[i][j]=S[i][j+1]-S[i][j];
	  if(S[i][j]<1)
	    S[i][j]=1;
	}
    }
  cout<<S[1][1]<<endl;
}


int main()
{
  t=scan();
  while(t--)
    test();
  return 0;
}
