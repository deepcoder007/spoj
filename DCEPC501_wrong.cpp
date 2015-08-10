#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

int arr[100009]; 
int dp[100009][4];

inline void test()
{
  int n;
  n=scan();
  register int i,j,k;
  for(i=0;i<n;i++)
  arr[i]=scan();
  if( n<=3 ) // i.e. pick all
    {
      int sum=0;
      for(i=0;i<n;i++)
	sum+=arr[i];
      cout<<sum<<endl;
    }
  memset(dp,0,sizeof(dp));
  int tmp;  // for any temp storage
  int maxima=0;
  for(i=0;i<n;i++)  // for all the positions
    {
      //      cout<<"For pos : "<<i<<endl;
      for(j=1;j<=3;j++)  // for end of the last brick-> all 3 cases
	{
	  if( (i-j)>=0 )   // if (i-j) is a valid position
	    {
	      tmp=0;
	      for(k=0;k<j;k++)
		tmp+=arr[i-k];
	      for(k=1;k<=3;k++)  // for number of voids
		{
		  if( (i-j-k)>0 )  // if it even exists
		    {
		      dp[i][j]=max(dp[i][j],dp[i-j-k][k]+tmp);
		      maxima=max(maxima,dp[i][j]);
		    }
		}
	    }
	}
      //      cout<<" Done for pos : "<<i<<endl;
    }
  cout<<maxima<<endl;

}

int main()
{
  int t=scan();
  while( t-- )
    test();
  return 0;
}
