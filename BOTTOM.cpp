#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<set>
#include<queue>
using namespace std;
// all arrays are 1 ary

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
int g_index[5002];   // for index of the algo -> -1 means not discovered
int g_low[5002];     // the lowest index of the stack
bool g_stack[5002];   // to tell if it is on stack or not
int curr_idx;   // the current index
stack<int> st;

inline void connect(int n)    // start the algo for node n
{
  g_index[n]=g_low[n]=curr_idx++;  // initialize it
  g_stack[n]=true;   // i.e. it is on stack now
  st.push(n);
  register int i,j;
  for( i=1 ; i<=v; i++ )
    {
      if( g[n][i] )  // if there is an edge
	{
	  if( g_index[i] == 0  ) //not discovered
	    {
	      connect(i);
	      g_low[n]=min(g_low[n],g_low[i]);
	    }
	  else if( g_stack[i]  )
	    {
	      g_low[n]=min(g_low[n],g_low[i]);
	    }
	}
    }
  int tmp;
  if( g_index[n]==g_low[n] )  // if this is the root
    {
      while( !st.empty() )
	{
	  tmp=st.top();
	  st.pop();
	  g_stack[tmp]=false;
	  g_low[tmp]=g_index[n];  // shift the index
	  if( tmp==n ) break;
	}
    }
}

inline void bottom()
{
  register int i,j;
  for(i=1;i<=v;i++) g_stack[i]=true;  // push all on the stack
  for(i=1;i<=v;i++)
    {
      for(j=1;j<=v;j++)
	{
	  if( g[i][j] )  // if there is a link
	    {
	      if( g_low[i]!=g_low[j] )
		{
		  g_stack[i]=false;
		  break;
		}
	    }
	}
    }
  for(i=1;i<=v;i++)
    if( g_stack[i] )
      cout<<i<<" ";
  cout<<endl;
}

// first implement the tarjan's algo
inline void tarjan()
{
  memset(g_index,0,sizeof(g_index));
  memset(g_low,0,sizeof(g_low));
  memset(g_stack,0,sizeof(g_stack));
  curr_idx=1;   // the index to be assigned
  while(!st.empty() ) st.pop();   // empty the stack
  register int i;
  for(i=1;i<=v;i++)   // for all the vertices
    {
      if( g_index[i]==0 )  // i.e. not discovered
	{
	  connect(i);
	}
    }
  // now find the head

}


int main()
{
  register int i,j,m,n;
  while(1)
    {
      v=scan();
      if(v==0) break;
      e=scan();
      memset(g,0,sizeof(g));
      for(i=0;i<e;i++)
	{
	  m=scan(); n=scan();
	  g[m][n]=true;
	}
      tarjan();
      bottom();
    }
  return 0;
}
