#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

// a dp problem in 2D

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
  register char c=getchar_unlocked();
  while( c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int m,n;
int dp[2][210][210];    // 0-> left facing , 1-> right facing
char input[210][210];

int get(int i,int j,int f)    // f -> 0 for left and 1 for right
{
  //  cout<<"for (i,j) : "<<i<<" "<<j<<endl;
  if( i<0 || i>=m || j<0 || j>=n ) return 0;   // i.e. out of bound
  if( input[i][j]=='#' ) return 0;
  if( dp[f][i][j]!=-1 ) return dp[f][i][j];
  // otherwise perform the dp
  if( f==1 )    // the face is at the right
    {
      int a=get(i,j+1,1);
      int b=get(i+1,j,0);
      dp[f][i][j]=max(a,b);
    }
  else
    {
      int a=get(i,j-1,0);
      int b=get(i+1,j,1);
      dp[f][i][j]=max(a,b);
    }
  if( input[i][j]=='T')
    dp[f][i][j]++;
  return dp[f][i][j];

}

inline void test()
{
  //  cout<<"INSIDE TEST"<<endl;
  m=scan(); n=scan();
  register int i,j;
  for(i=0;i<=200;i++)
    for(j=0;j<=200;j++)
      dp[0][i][j]=dp[1][i][j]=-1;
  for(i=0;i<m;i++)
    cin>>input[i];
  //  cout<<"here"<<endl;
  cout<<get(0,0,1)<<endl;
}



int main()
{
  int t=scan();
  while( t-- )
    test();
  return 0;
}
