#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

inline long long max(long long i,long long  j)
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
long long dp[100009][4];
int n;

inline long long get_count(int k,int l)   // get_count if we start at the k'th block with l blocks in a row
{
  if( dp[k][l]!=0 ) return dp[k][l];
  if( k>n ) return 0;   // i.e. start of the block is out of bound
  long long  tmp=0;
  register int i,j;
  if( (k+l-1)<=n ) 
    for( i=0;i<l;i++)
      tmp+=arr[k+i]; 
  else
    {
      for( i=0;(k+i)<=n ;i++ )
	{
	  tmp+=arr[k+i];
	}
      return tmp;
    }
  for(i=1;i<=3;ipp++)
    dp[k][l]=max(dp[k][l],tmp+get_count(k+2*l,i));
  return dp[k][l];
}



inline void test()
{
  n=scan();
  register int i,j,k;
  for(i=1;i<=n;i++)
    arr[i]=scan();
  memset(dp,0,sizeof(dp));
  cout<<max(get_count(1,1),max(get_count(1,2),get_count(1,3)))<<endl;
}

int main()
{
  int t=scan();
  while( t-- )
    test();
  return 0;
}
