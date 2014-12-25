#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

inline int min(int a,int b) 
{  if( a>b ) return b;
	else return a; }

bool covered[100009];        // whether the vertex is in the parent 
int n,t1,t2;
vector<vector<int> > g(100009);
int dpi[100009];    // the dp with node included
int dpe[100009];    // the dp with node excluded

int dfs(int);
int dfse(int);
int dfsi(int);

int dfsi(int a)    // the dpi at graph i [
{
	if(dpi[a]!=-1) return dpi[a];   // if this is the second time
	register int i;
	covered[a]=true;
	int sum=0;
	for(i=0;i<g[a].size();i++)
	{
		if(covered[g[a][i]]==false )   // i.e. not the parent
		{ sum+=dfs(g[a][i]); }
	}
	covered[a]=false;
	dpi[a]=1+sum;
	return dpi[a];
}

int dfse(int a)    // the dpe at graph i
{
	if(dpe[a]!=-1) return dpi[a];
	register int i;
	covered[a]=true;
	int sum=0;
	for(i=0;i<g[a].size();i++)
	{
		if(covered[g[a][i]]==false)
		{ sum+=dfsi(g[a][i]); }
	}
	covered[a]=false;
	dpe[a]=sum;
	return dpe[a];
}

int dfs(int a)
{
	dfsi(a);
	dfse(a);
	return min(dpi[a],dpe[a]);
}


int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	memset(dpi,-1,sizeof(dpi));
	memset(dpe,-1,sizeof(dpe));
	memset(covered,false,sizeof(covered));
	dfs(1);
	printf("%d\n",dfs(1));
	return 0;
}
		




