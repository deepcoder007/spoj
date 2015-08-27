// implementation of the ford fulkerson algorithm

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<cstring>
#include<utility>
#include<climits>
#define mp make_pair
#define pb push_back
#define REP(i,a,b) for(i=a;i<=b;i++)
#define FOR(i,a,b) for(i=a;i<b; i++)
#define sci(x) scanf("%d",&x)
#define sc2i(x,y) scanf("%d%d",&x,&y)
#define scli(x) scanf("%I64d", &x)
#define scl2i(x,y) scanf("%I64d%I64d",&x,&y)
#define debug(n) cout<<__LINE__<<" #n "<<n<<endl
#define debug2(a,b) cout<<__LINE__<<" #a "<<a<<" #b "<<b<<endl
#define debug3(a,b,c)  cout<<__LINE__<<" #a "<<a<<" #b "<<b<<" #c "<<c<<endl
#define fill(a,x) memset(a,x,sizeof(a))
#define trace(x) cout<<__FUNCTION__<<" : "<<__LINE__<<" #x "<<x<<endl
#define trace2(x,y) cout<<__FUNCTION__<<" : "<<__LINE__<<" #x "<<x<<" #y "<<y<<endl
#define tracea(x,a,b) cout<<__FUNCTION__<<" : "<<__LINE__<<" #x "; FOR(i,a,b) cout<<x[i]<<" , " ; cout<<endl;
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int ui;
typedef long double ld;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;

inline int scan()
{
  register int n=0;
  register int sign=1;
  register char c=getchar_unlocked();
  while( (c<'0' || c>'9') && c!='-' )
    c=getchar_unlocked();
  if( c=='-' )
    {
      sign=-1;
      c=getchar_unlocked();
    }
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int g[100][100];   // the graph
int rg[100][100];  // the residual graph
int n;   // the nodes
int e;   // the count of edges
int s,t;  // the source and the sink
int p[100];  // the parent nodes
bool vis[100];   // if the node is visited or not


bool haspath()  // returns true if there is an augmented path from source
{
  int tmp1,tmp2,tmp3;
  queue<int> q;
  q.insert(s);  
  fill(p,0);
  fill(vis,false);  
  vis[s]=true;
  bool res=false;   // if the sink is found
  while(!q.empty())
    {
      tmp1=q.front();
      q.pop();
      FOR(tmp2,0,n) // for all the nodes
	{
	  if( !vis[tmp2] && rg[tmp1][tmp2]>0 )  // i.e. there is a residual capacity and the node is not already visited
	    {
	      q.push(tmp2);
	      p[tmp2]=tmp1;
	      vis[tmp2]=true;
	      if( tmp2 == t ) res=true;
	    }
	}
    }
  return res; // true if sink is approachable
}


int main()
{
  register int i,j;
  int tmp1,tmp2,tmp3;
  sci(n);
  fill(g,0);
  fill(rg,0);
  sci(e);
  FOR(i,0,e)
    {
      // format of the edge -> source,sink,weight
      sc2i(tmp1,tmp2); sci(tmp3);
      g[tmp1][tmp2]=tmp3;
      rg[tmp1][tmp2]=tmp3;  
    }
  sc2i(s,t);
  // mas-flow algo
  while(haspath())
    {
      // find the min dist
      tmp1=t;  // the final node
      tmp2=p[t];   // the earlier node
      tmp3=rg[tmp2][tmp1];  
      while(1)
	{
	  tmp3=min(tmp3,rg[tmp2][tmp1]);
	  if( tmp2==s ) break; // i.e. the source
	  tmp2=p[tmp2];
	  tmp1=p[tmp1];
	}
      // now remove tmp3 from the residual capacity
      tmp1=t;
      while( tmp1!=s )
	{
	  rg[p[tmp1]][tmp1]-=tmp3;
	  rg[tmp1][p[tmp1]]+=tmp3;
	}
    }

  return 0;
}

