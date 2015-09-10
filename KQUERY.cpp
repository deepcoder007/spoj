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
  return sign*n;
}
// often implementing stack and queue via array can be faster and better 


struct st
{
  int val,l,r,idx;
  bool q;   // true if this is a query
  bool operator < ( st s ) const
  {
    if( val==s.val ) return q<s.q;
    return val<s.val;
  }
};

int n,q;
st req[300000];
int bit[40000];
int ans[300000];

void add(int idx)
{
  while(idx<=n)
    {
      bit[idx]++;
      idx+=(idx&-idx);
    }
}

int get(int idx)
{
  int sum=0;
  while(idx>0)
    {
      sum+=bit[idx];
      idx-=(idx&-idx);
    }
  return sum;
}

int main()
{
  register int i,j;fill(bit,0);
  sci(n);
  FOR(i,0,n) sci(req[i].val), req[i].q=false,req[i].idx=i+1;
  sci(q);
  FOR(i,0,q) sc2i(req[i+n].l,req[i+n].r), sci(req[i+n].val),req[i+n].q=true,req[i+n].idx=i;
  // now start the processing
  sort(req,req+n+q);


  FOR(i,0,n+q)   
    {
      if( !req[i].q )   // if this is an addition
	add(req[i].idx+1);
      else
	{
	  int res = get(req[i].r)-get(req[i].l-1);
	  ans[ req[i].idx ]=(req[i].r-req[i].l+1)-res;
	}
    }
  // print the output
  FOR(i,0,q)
    cout<<ans[i]<<endl;
  return 0;
}
