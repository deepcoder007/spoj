#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
// the array i am taking are 1-ary
bool graph[110][110]; // the graph to store the edges -> the edges are directed
bool reverse_graph[110][110];  // the reverse of the graph given above
bool marked[110];    // used for marking in dfs/bfs
int k,l,m,n,mm;
stack<int> stk;
vector<int> v;   

void sort_n_prn()
{
  register int i,j;
  register int z;
  for( i = 0 ; i<n ; i++ )
    {
      for( j=1 ; j<n ; j++ )
	{
	  if( v[j-1]>v[j] && ( graph[j-1][j]==false && graph[j][j-1]==false ) ) // i.e. no dependency
	    {
	      z = v[j-1];
	      v[j-1] = v[j];
	      v[j] = z;
	    }
	}
    }
  for( i=0 ; i<n ; i++ )
    {
      cout<<v[i]+1<<" ";
    }
  cout<<endl;

}

int dfs2(int ele)
{
  marked[ele]=true;  // mark the node visited
  register int i,j;
  for( i=0 ;i<n;i++)
    {
      if( marked[i]==false && reverse_graph[ele][i]==true ) 
	dfs2(i);
    }
  stk.push(ele);  // now push at the end
}

int dfs1()
{
  register int i,j;
  for(i=0;i<n;i++)
    {
      if(marked[i]==false)
	{
	  dfs2(i);
	}
    }
  //pop the stack
  while( !stk.empty() )
    {
      v.push_back(stk.top());
      stk.pop();
    }
}

int main()
{
  cin>>n>>m;
  memset(graph,0,sizeof(bool)*110*110);
  memset(marked,0,sizeof(bool)*110);
  memset(reverse_graph,0,sizeof(bool)*110*110);
  register int i,j;
  for( i=0 ; i<m ;i++)
    {
      cin>>k>>l;
      while(l--)
	{
	  cin>>mm;
	  graph[k-1][mm-1]=true;
	  reverse_graph[mm-1][k-1]=true;
	}
    }
  dfs1();
  sort_n_prn();  // sort and print the vector
  return 0;
}
  


