#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
// use a DFS/BFS based approach to find arbitrage

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while(c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int t,n;  // n is the number of nodes
string str_1,str_2,str_3;
map<string,int> m;
float g[35][35];
float ft1,ft2;

int main()
{
  register int i,j,k;
  int count=1 ; // the test case number
  while(1)
    {
      n=scan();
      if( n== 0 ) break;
      for(i=0;i<n;i++)
	{
	  cin>>str_1;
	  m[str_1]=i;
	}
      memset(g,0,sizeof(float)*35*35);
      t=scan();
      while(t--)
	{
	  cin>>str_1>>ft1>>str_2;
	  g[m[str_1]][m[str_2]]=ft1; 
	}
      // the floyd warshall algorithm
      for(k=0;k<n;k++) // the via node
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    if( g[i][j]<g[i][k]*g[k][j])
	      g[i][j]=g[i][k]*g[k][j];

      bool arbit=false;
      for(i=0;i<n;i++)
	if(g[i][i]>1.0)
	  arbit=true;
      if(arbit)
	printf("Case %d: Yes\n",count++);
      else
	printf("Case %d: No\n",count++);
    }
  return 0;
}
