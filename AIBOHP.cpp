#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

string in;
int dp[6200][6200];    // stores the number of addition deletion

int get(int x,int y)    // the coordinates are inclusive
{
  if( x>y ) return 0;
  if( x==y ) return 0;   // the base case
  if( dp[x][y] ) return dp[x][y];
  
  if( in[x]==in[y]) // i.e. first and last are same
    {
      dp[x][y]=get(x+1,y-1);
      return dp[x][y];
    }
  else
    {
      dp[x][y]=min(get(x+1,y),get(x,y-1))+1;
      return dp[x][y];
    }

}

void test()
{
  memset(dp,0,sizeof(dp));
  cin>>in;
  cout<<get(0,in.size()-1)<<endl;
}
  

int main()
{
  int t;
  cin>>t;
  while(t--)
    test();
  return 0;
}
