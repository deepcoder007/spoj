#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
// the array i am taking are 1-ary
bool graph[110][110];
bool reverse_graph[110][110];
bool vis[110];
int m,n;
bool change=false;  // to record if there is another dependent node on the the reverse graph

int main()
{
  register int i,j,k,l,o,p;
  cin>>n>>m;
  memset(graph,0,sizeof(bool)*110*110);
  memset(reverse_graph,0,sizeof(bool)*110*110);
  memset(vis,0,sizeof(bool)*110);
  for(i=0;i<m;i++)
    {
      cin>>k>>l;
      for(j=0;j<l;j++)
	{
	  cin>>o;
	  graph[k-1][o-1]=true;
	  reverse_graph[o-1][k-1]=true;
	}
    }


  for(i=0;i<n;i++) 
    {
      for(j=0;j<n;j++)  // for each node
	{
	  if( vis[j]==true )
	    continue;
	  change=false;
	  for( k=0;k<n;k++)
	    {
	      if( graph[j][k]==true && vis[k]==false ) // an univisited
		{
		  change=true;
		  break;
		}
	    }
	  if( change==false )  
	    {
	      cout<<j+1<<" ";
	      vis[j]=true;
	      break;
	    }
	}
    }
  cout<<endl;
  return 0;
}


