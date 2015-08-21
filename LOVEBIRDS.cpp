#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int dp[1009];   

int get_c(int k)   
{
  if( dp[k]!=-1 ) return dp[k];
  register int i,j;
  int sum=0;
  int c=0;   // c-> no. of elements on the left of the root node
  for(c=0;c<k;c++)   
    {
      sum+=(get_c(c)*get_c(k-c-1))%1908;
    }
  dp[k]=sum;
  return dp[k];
}


int main()
{
  int t,n;
  cin>>t;
  register int i,j;
  for(i=0;i<=1000;i++)
    dp[i]=-1;
  dp[0]=1;
  dp[1]=1;
  dp[2]=2;
  while(t--)
    {
      cin>>n;
      cout<<get_c(n)<<endl;
    }
  return 0;
}
