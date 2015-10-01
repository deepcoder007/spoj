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
int p,t,s,c;
int px[410],py[410],tx[210],ty[210];
map<int,VI > g;
int tmp1,tmp2,tmp3;


inline void test()
{
  register int i,j;
  sc2i(p,t),sc2i(s,c);
  FOR(i,0,p) sc2i(px[i],py[i]);
  FOR(i,0,t) sc2i(tx[i],ty[i]);
  g.clear();
  REP(i,0,p+t+1) g[i]=VI();  // init the graph
  REP(i,1,p) g[0].pb(i);   // source to person
  REP(i,p+1,p+t) g[p+t].pb(p+t+1);   // taxi to dest
  REP(i,1,p)
    REP(j,p+1,p+t)
    {
      tmp1=abs(px[i-1]-tx[j-p-1])+abs(py[i-1]-tx[j-p-1]);
      tmp1*=400;
      if( tmp1<=c )   // if edge possible
	g[i].pb(j);
    }


}

int main()
{
  int tt=scan();
  while(tt--)
    test();
  return 0;
}

