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
vector<int> gi[100009];    // the inverse of this graph

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

stack<int> st;
bool visited[100009];  

void dfs(int k)
{
  visited[k]=true;
  register int i;
  for(i=0; i<g[k].size() ;i++ ) // for all the adjacent nodes
    {
      if( !visited[g[k][i]] )
	{
	  dfs(g[k][i]);
	}
    }
  st.push(k);
}

set<int> set1; // the set of 
set<int>::iterator it;

void dfs2(int k)
{
  visited[k]=true;
  register int i;
  for(i=0;i<gi[k].size() ; i++)
    {
      if( !visited[gi[k][i]] )
	{
	  dfs(g[k][i]);
	}
    }
  set1.insert(k);
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
      gi[tmp2].push_back(tmp1);
    }
  memset(visited,0,sizeof(visited));
  for( i=1; i<=n; i++)
    {
      if( !visited[i] )
	dfs(i);
    }
  // print the first component
  memset(visited,0,sizeof(visited));
  stack<int> st2;
  while( !st.empty() )
    {
      st2.push(st.top());
      st.pop();
    }
  dfs2(st2.top());
  cout<<set1.size()<<endl;
  for( i=1 ;i<=n;i++)
    if( visited[i] )
     	cout<<i<<" ";
  cout<<endl;
  return 0; 
}
