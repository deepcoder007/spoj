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
int bricks[100009][4]; // bricks[i][j] -> sum from a j count brick of size 2*j which ends at i'th brick
int dp[100009];

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
  int tmp;
  // init the brick
  for(i=0;i<n;i++)
    {
      for(j=1;j<=3;j++) // for all the count of brick
	{
	  if( (i-2*j+1)<0 )   // brick not possible
	    {
	      bricks[i][j]=0;  
	      continue;
	    }
	  tmp=0;
	  for(k=i-j ; k>(i-2*j) ;k-- )
	    tmp+=arr[k];
	  bricks[i][j]=tmp;
	}
    }
  /*
  cout<<"INIT of the bricks: "<<endl;
  for(i=1;i<=3;i++)
    {
      for(j=0;j<n;j++)
	cout<<bricks[j][i]<<" ";
      cout<<endl;
    }
  cout<<"INIT done"<<endl;
  */
  // now make a selection of bricks using the dp
  int max_idx=0;   // the max index reached-> in case the last block in incomp.
  int maxima=0;    // the maxima reached
  memset(dp,0,sizeof(dp));
  dp[2]=bricks[1][1];
  dp[4]=max(bricks[3][2],bricks[1][1]+bricks[3][1]) ;
  dp[6]=max(bricks[5][3],max(bricks[3][2]+bricks[5][1],max(bricks[1][1]+bricks[5][2],bricks[1][1]+bricks[3][1]+bricks[5][1])));

  for(i=1;i<=n;i++ )   // the dp array is 1-ary
    {
      for(j=1;j<=3;j++ )   // for all the brick size
	{
	  if( (i-2*j+1)>0 && dp[i-2*j]>0 ) // if within bounds and non zero
	    {
	      dp[i]=max(dp[i],dp[i-2*j]+bricks[i-1][j]);
	      //	      maxima=max(dp[i],maxima);
	      //	      max_idx=max(max_idx,i);
	    }
	}
    }
  /*
  cout<<"The dp array : "<<endl;
  for(i=1;i<=n;i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  cout<<"dp array done: "<<endl;
  */
  int mx=0;
  for( i=0 ; i<6 ; i++ )  // (n-i) -> end of last full brick 
    {
      tmp=0;    // the sum of the tail
      for(j=1;j<=3;j++ )
	if( (n-1-i+j)<n )   // if in range
	  tmp+=arr[n-1-i+j];
	else
	  break;
      mx=max(mx,dp[n-i]+tmp);
    }
  cout<<mx<<endl;   // the final output
}

int main()
{
  int t=scan();
  while( t-- )
    test();
  return 0;
}
