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
#include<queue>
#include<deque>
#define mp make_pair
#define pb push_back
#define dbg() cout<<"DEBUG"<<endl
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
typedef map<int,int> mii;

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
// often implementing stack and queue via array can be faster and better 
int n,m,s,d; int tmp1,tmp2,tmp3;
int g[510][510];
int p[510];
bool vis[510];
int dist[510];
map<int,VI > gm;   // the map of the same graph

struct pq_comp 
{
  bool operator ()(int a,int b) // compare the element a and b
    {
      if( dist[a]!=-1 && dist[b]!=-1 )  return dist[a]>dist[b];  
      else if( dist[a]!=-1 ) return dist[a];
      else if( dist[b]!=-1 ) return dist[b];
      else return false ;   // the random choice
    }
};

// returns the length of the shortest path and cancels/delete that path
int bfs_short()
{
  int out=0;
  register int i,j;
  fill(vis,0),  fill(p,-1) ,fill(dist,-1);
  priority_queue<int,VI,pq_comp > pqs;   // for use with the dijkstra's algo
  dist[s]=0; pqs.push(s);   // vis is true for only those which are already part of the dijkstra's tree
  while( !pqs.empty() )
    {
      tmp1=pqs.top(), pqs.pop(), vis[tmp1]=true;
      FOR(i,0,gm[tmp1].size()) // for all adjacent nodes to this node
	if( !vis[gm[tmp1][i]] )
	  {
	    if( dist[gm[tmp1][i]]==-1 ) dist[gm[tmp1][i]]=(dist[tmp1]+g[tmp1][ gm[tmp1][i] ] ), pqs.push(gm[tmp1][i]);  // if new discovered
	    else dist[gm[tmp1][i]]=min( dist[gm[tmp1][i]] , dist[tmp1]+g[tmp1][ gm[tmp1][i] ] ) ;   // only relax the path in case required
	    if( dist[gm[tmp1][i]] == ( dist[tmp1]+g[tmp1][ gm[tmp1][i] ] ) )  p[ gm[tmp1][i] ] = tmp1;  // update the parent in this case
	  }
    }

  // calculate the minimum distance and remove that path
  tmp1=d;
  while( tmp1!=s )   
    {
      if( p[tmp1]==-1 ) return -1;   // path not reachable
      out+=g[p[tmp1]][tmp1];  // add the edge length
      g[p[tmp1]][tmp1]=-1;
      gm[p[tmp1]].erase(find(gm[p[tmp1]].begin(),gm[p[tmp1]].end(),tmp1));
      tmp1=p[tmp1];
    }
  return out;
}


int main()
{
  register int i,j;
  int ans,ans2;
  while(1)
    {
      fill(g,-1), gm.clear();
      sc2i(n,m);
      FOR(i,0,n) gm[i]=VI();
      if( n==0 && m==0 ) return 0;
      sc2i(s,d); 
      FOR(i,0,m) sc2i(tmp1,tmp2), sci(tmp3), g[tmp1][tmp2]=tmp3, gm[tmp1].pb(tmp2) ;  // input of the edges
      ans=bfs_short();
      while(1)
	{
	  ans2=bfs_short();
	  if( ans2!=ans )
	    {
	      cout<<ans2<<endl;
	      break;
	    }
	}
    }
}
