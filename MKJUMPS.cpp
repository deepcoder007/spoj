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

int t,n;
bool board[11][11];   // to check if exist
bool vis[11][11];   // to mark visited
int count;
int start;

int a,b;
int tmp1,tmp2,tmp3;

int x[]={-2,-2,-1,-1,+1,+1,+2,+2};
int y[]={-1,+1,-2,+2,-2,+2,-1,+1};

int recur(int i,int j)   //return the count of no. of square reached
{
  vis[i][j]=true;     // mark the cell visited
  register int a,b;
  int mx=0;
  for(a=0;a<8;a++)
    {
      if( board[i+x[a]][j+y[a]] && !vis[i+x[a]][j+y[a]] )  // if on board
	{
	  mx=max(mx,recur(i+x[a],j+y[a]));
	}
    }
  vis[i][j]=false;
  return (mx+1);
}

int main()
{
  t=1;
  register int i,j;
  while(1)
    {
      memset(vis,0,sizeof(vis));
      memset(board,0,sizeof(board));
      count=0;
      cin>>n;   // the number of rows
      if( n==0 ) break;
      for(i=0;i<n;i++)
	{
	  cin>>a>>b;    // the no. of columns to leave and no. to accept
	  count+=b;     // the number of cells that are on board
	  for(j=0;j<a;j++);
	  for(;j<(a+b);j++)
	    board[i][j]=true;  
	}
      //      cout<<"no. of suqares on board: "<<count<<endl;
      for(i=0;i<n && !board[0][i] ; i++);   // when it stops the i will be true
      start=i;
      count=count-recur(0,start);
      if( count == 1 )
	printf("Case %d, %d square can not be reached.\n",t,count);
      else
	printf("Case %d, %d squares can not be reached.\n",t,count);
      t++;
    }
  return 0;
}
