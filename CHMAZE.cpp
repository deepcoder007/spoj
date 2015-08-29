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

int t,r,c,p;   // p-> is the pattern count
int g[15][25][25];   // the graph

int x_nxt[5]={-1,0,1,0,0};
int y_nxt[5]={0,1,0,-1,0};

struct coord
{
  int x,y,pat,st;  // (x,y) coordinate with pattern p in st steps
};

bool is_allowed(int i,int j,int k)
{
  if( j<0 || j>=r || k<0 || k>=c || g[i][j][k]==1 ) return false;  //not reach
  else return true;
}

// -1 means not reachable
int can_reach()
{
  register int i,j;
  bool vis[15][25][25];   // vis[i][j][k]  -> visited(j,k) in i'th node
  fill(vis,0);
  queue<coord> q;   // the queue for the bfs
  q.push((coord){0,0,0,0});   // the first step
  vis[0][0][0]=true;   // mark it visited
  int nxt; // the next pattern
  int tmp1,tmp2,tmp3;
  coord ctmp,fin;  // fin-> is the final one
  bool init_final=false; // if ever a final occured
  while( !q.empty() )
    {
      ctmp=q.front();
      //      cout<<" on coordinate :  ( "<<ctmp.x<<" , "<<ctmp.y<<" ) p :"<<ctmp.pat<<endl;
      q.pop();
      FOR(i,0,4)
	{
	  tmp1=ctmp.x+x_nxt[i];
	  tmp2=ctmp.y+y_nxt[i];
	  tmp3=(ctmp.pat+1)%p;
	  //	  if( tmp1==(r-1) && tmp2==(c-1) ) return ctmp.st;
	  if( !vis[tmp3][tmp1][tmp2] &&  is_allowed(tmp3,tmp1,tmp2) )
	    {
	      q.push((coord){tmp1,tmp2,tmp3,ctmp.st+1});
	      //	      cout<<" From : ("<<ctmp.x<<","<<ctmp.y<<") p :"<<ctmp.pat<<" : to : ("<<tmp1<<","<<tmp2<<") p: "<<tmp3<<endl;
	    }
	  vis[tmp3][tmp1][tmp2]=true;
	}
      if( ctmp.x==(r-1) && ctmp.y==(c-1) )
	return ctmp.st;
    }
  return -1;
}


int main()
{
  register int i,j,k;
  string stmp1;
  int tmp1,tmp2;
  t=1;
  while(1)
    {
      //      cout<<endl<<endl<<endl;
      sc2i(r,c); sci(p);
      if( r==0 && c==0 ) return 0;   // the last case
      FOR(i,0,p)
	{
	  FOR(j,0,r)
	    {
	      cin>>stmp1;
	      FOR(k,0,c)
		g[i][j][k]=stmp1[k]-'0';
	    }
	}

      // now start the bfs
      int res=can_reach();
      if( res!=-1 )
	printf("Case %d: Luke and Leia can escape in %d steps.\n",t,res);
      else
	printf("Case %d: Luke and Leia cannot escape.\n",t);
      t++;
    }

  return 0;
}
