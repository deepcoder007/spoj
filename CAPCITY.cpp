#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<stack>
#include<cstring>
using namespace std;
// use the last component as the candidate for the capital city
// tarjan algorithm works better for this case
// all arrays are 1-ary
int n,m;
vector<int> g[100009];   // the adjacency list rep of graph

inline int scan()
{
  register int n=0;
  register int c;
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

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

stack<int> st;
bool visited[100009];  
int g_index[100009];
int g_low[100009];
bool g_stack[100009];
int curr_idx=1;

void connect(int k)   
{
  g_index[k]=g_low[k]=curr_idx++;
  g_stack[k]=true;
  st.push(k); 
  register int i,j;
  for(i=0;i<g[k].size(); i++ ) // for all the adjacent nodes
    {
      if( !g_index[g[k][i]] ) // if not discovered
	{
	  connect(g[k][i]);
	  g_low[k]=min(g_low[k],g_low[g[k][i]]);
	}
      else if( g_stack[g[k][i]] )
	{
	  g_low[k]=min(g_low[k],g_low[g[k][i]]);
	}
    }
  //now take care of stack
  if( g_index[k]==g_low[k] )
    {
      while( !st.empty() )  
	{
	  int tmp=st.top();
	  st.pop();
	  g_stack[tmp]=false;
	  g_low[tmp]=g_index[k];
	  if( tmp==k) break;
	}
    }
}
 
void tarjan()
{
  memset(visited,0,sizeof(visited));
  memset(g_index,0,sizeof(g_index));
  memset(g_low,0,sizeof(g_low));
  memset(g_stack,0,sizeof(g_stack));
  register int i;
  for(i=1;i<=n;i++ )
    if( !g_index[i]  )
      connect(i);
}

void bottom()
{
  register int i,j;
  for(i=1;i<=n;i++ ) g_stack[i]=true;   
  for(i=1;i<=n;i++)
    for(j=0;j<g[i].size();j++)
      {
	if( g_low[i]!=g_low[g[i][j]] ) {
	  g_stack[i]=false;
	  break;
	}
      }
  int count =0 ;
  for( i=1 ;i<=n; i++)
    {
      if( g_stack[i] ) count++;
    }
  cout<<count<<endl;
  for(i=1;i<=n;i++)
    {
      if(g_stack[i]) printf("%d ",i);
    }
  cout<<endl;
}

int main()
{
  int tmp1,tmp2,tmp3; 
  register int i,j;
  n=scan(); m=scan();
  for(i=0;i<m;i++)
    {
      tmp1=scan(); tmp2=scan();
      g[tmp1].push_back(tmp2);
    }
  tarjan();
  bottom();
  return 0; 
}
