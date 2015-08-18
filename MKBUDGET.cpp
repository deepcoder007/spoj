#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

inline int scan()
{
  register int n=0;
  register char c=getchar_unlocked();
  while( c<'0' || c>'9' )
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

template<class T>
inline T max(T i,T j)
{
  if( i>j ) return i;
  else return j;
}

template<class T>
inline T MIN(T i,T j)
{
  if( i<j ) return i;
  else return j;
}

//base case is the last month
unsigned long long dp[26][310];   // dp[i][j] -> min cost if we start the ithe month with j workers  where j>arr[i]
int arr[26];  
int ch,s,sp, wm;   // wm -> no. of months to wait before firing a worker
int n;   // the number of months
int tmp1,tmp2,tmp3;
int pay,curr;   

// return the ctc if we start the i'th month with j workers
unsigned long long get_c(int i,int j) 
{
  if( dp[i][j]!=-1 ) return dp[i][j];
  if( j<arr[i] ) return -1;     // invalid state
  if( i>=n ) return -1;
  register int a,b;
  //  cout<<"Called for : "<<i<<"  "<<j<<endl;
  a=arr[i+1]+1;
  dp[i][j]=get_c(i+1,arr[i+1])+s*j;
  if( arr[i+1]>j ) // will have to buy more
      dp[i][j]+=(ch*(arr[i+1]-j));
  else
      dp[i][j]+=(sp*(j-arr[i+1]));
  for(  ; a<=300 ; a++ )    // for all the workers of next position
    {
      if( a>j )   // if next step has more workers then the current
	  dp[i][j]=MIN( dp[i][j], get_c(i+1,a)+s*j+ch*(a-j) );
      else
	  dp[i][j]=MIN( dp[i][j], get_c(i+1,a)+s*j+sp*(j-a) );
    }
  return dp[i][j];
}


int main()
{
  int t;
  register int i,j;
  t=1;
  while(1)
    {
      n=scan();
      if( n==0 ) return 0;
      ch=scan() ; s=scan(); sp=scan();
       // init the base case
      for(i=0;i<n;i++)
	arr[i]=scan();
      for(i=0;i<n;i++)
	for(j=0;j<=300;j++)
	  dp[i][j]=-1;
      for(i=arr[n-1];i<=310;i++)
	dp[n-1][i]=s*i;   
      printf("Case %d, cost = $%lld\n",t,(get_c(0,arr[0])+ch*arr[0]));
      //      cout<<"ANS: "<<(get_c(0,arr[0])+ch*arr[0])<<endl;
      t++;
    }
  return 0;
}

