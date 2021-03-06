#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
// a classic 

int dp[200][200];   // the dp
char sym[200];  // the symbols
int num[200];    // the numbers

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

// the max value that can be obtained
int max_count(string in)
{
  // read the input
  memset(dp,0,sizeof(dp));
  register int i,j,k;
  int n=in.size();
  for(i=0,j=0,k=0;i<n;i++)
    {
      if( in[i]>='0' && in[i]<='9' )
	num[j++]=in[i]-'0';
      else 
	sym[k++]=in[i];
    }
  int num_count=j;     // the number of numbers
  // init it
  for( i=0; i<num_count; i++)  // the base case
    dp[i][i]=num[i];  
  for( i=2;i<=num_count;i++ )     // count the number of numbers
    {
      for(j=0;(j+i)<=num_count; j++ )   // for all the starting positions
	{
	  for( k=j+1 ; k<(j+i) ;k++ )   // for all the starting second positions
	    {
	      if( sym[k-1]=='+' )    // the addition case
		{
		  dp[j][j+i-1]=max( dp[j][k-1]+dp[k][i+j-1] , dp[j][j+i-1] );
		}
	      else if( sym[k-1]=='*' )
		{
		  dp[j][j+i-1]=max( dp[j][k-1]*dp[k][i+j-1] , dp[j][j+i-1] );
		}
	    }
	}
    }
  return dp[0][num_count-1];	      
}

// the max value that can be obtained
int min_count(string in)
{
  // read the input
  memset(dp,0,sizeof(dp));
  register int i,j,k;
  int n=in.size();
  for(i=0,j=0,k=0;i<n;i++)
    {
      if( in[i]>='0' && in[i]<='9' )
	num[j++]=in[i]-'0';
      else 
	sym[k++]=in[i];
    }
  int num_count=j;     // the number of numbers
  // init it
  for( i=0; i<num_count; i++)  // the base case
    dp[i][i]=num[i];  
  for( i=2;i<=num_count;i++ )     // count the number of numbers
    {
      for(j=0;(j+i)<=num_count; j++ )   // for all the starting positions
	{
	  for( k=j+1 ; k<(j+i) ;k++ )   // for all the starting second positions
	    {
	      if( sym[k-1]=='+' )    // the addition case
		{
		  if( dp[j][j+i-1] )
		    dp[j][j+i-1]=min( dp[j][k-1]+dp[k][i+j-1] , dp[j][j+i-1] );
		  else 
		    dp[j][j+i-1]=( dp[j][k-1]+dp[k][i+j-1] );
		}
	      else if( sym[k-1]=='*' )
		{
		  if( dp[j][j+i-1] )
		    dp[j][j+i-1]=min( dp[j][k-1]*dp[k][i+j-1] , dp[j][j+i-1] );
		  else 
		    dp[j][j+i-1]=( dp[j][k-1]*dp[k][i+j-1] );
		}
	    }
	}
    }
  return dp[0][num_count-1];	      
}


int main()
{
	int n;
	cin>>n;
	string in;
	while(n--)
	{
		cin>>in;
		cout<<max_count(in)<<" "<<min_count(in)<<endl;
	}
	return 0;
}
