#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
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

int n,m;
int count;
vector<int> g[1000000];
bool visited[1000000];

void dfs(int k)
{
  visited[k]=true;
  register int i;
  for(i=0;i<g[k].size();i++)
    if( !visited[g[k][i]] )
      {
	dfs(g[k][i]);
      }
}

int main()
{
  memset(g,0,sizeof(g));
  memset(visited,0,sizeof(visited));
  n=scan();
  m=scan();
  count=0;
  register int i,j;
  string str;
  for(i=0;i<n;i++)
    {
      cin>>str;
      for(j=0;j<m;j++)
	{
	  if( str[j]=='S' )
	    {
	      g[i*m+j].push_back((i+1)*m+j);
	      g[(i+1)*m+j].push_back(i*m+j);
	    }
	  else if( str[j]=='W' )
	    {
	      g[i*m+j].push_back(i*m+j-1);
	      g[i*m+j-1].push_back(i*m+j);
	    }
	  else if( str[j]=='E' )
	    {
	      g[i*m+j].push_back(i*m+j+1);
	      g[i*m+j+1].push_back(i*m+j);
	    }
	  else if( str[j]=='N' )
	    {
	      g[i*m+j].push_back((i-1)*m+j);
	      g[(i-1)*m+j].push_back(i*m+j);
	    }
	}
    }
  for(i=0;i<(m*n);i++)
    {
      if( !visited[i] )  
	{
	  visited[i]=true;
	  count++;
	  dfs(i);
	}
    }
  cout<<count<<endl;
  return 0;
}
    



