#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while( c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}
int v,e;
bool g[5002][5002];  // the graph-> alternate option can be using the bitset

int main()
{
  register int i,j,k,m,n;
  while(1)
    {
      v=scan();
      if( v==0 ) break;
      e=scan();
      memset(g,0,sizeof(g));
      for(i=0;i<e;i++)
	{
	  m=scan();  n=scan();
	  g[m][n]=true;
	}
      // make the graph covering
      for( k=1; k<=v; k++) 
	for( i=1 ; i<=v; i++ )
	  for( j=1 ; j<=v; j++ )
	    if( !g[i][j] )  // otherwise there is no use of further steps
      	      if( g[i][k] && g[k][j] )
		g[i][j]=true;
      bool corr;
      for( i=1 ; i<=v; i++ )   // check each for sink one by one
	{
	  corr=true;   // shows that no contradiction till now
	  for(j=1; j<=v; j++ )
	    if( g[i][j] )
	      if( !g[j][i] )
		corr=false;
	  if( corr )
	    cout<<i<<" ";
	}
      cout<<endl;
    }
  return 0;
}	  

