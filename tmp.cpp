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
#define debug(n) cerr<<__LINE__<<" #n "<<n<<endl
#define debug2(a,b) cerr<<__LINE__<<" #a "<<a<<" #b "<<b<<endl
#define debug3(a,b,c)  cerr<<__LINE__<<" #a "<<a<<" #b "<<b<<" #c "<<c<<endl
#define fill(a,x) memset(a,x,sizeof(a))
#define trace(x) cerr<<__FUNCTION__<<" : "<<__LINE__<<" #x "<<x<<endl
#define trace2(x,y) cerr<<__FUNCTION__<<" : "<<__LINE__<<" #x "<<x<<" #y "<<y<<endl
#define tracea(x,a,b) cerr<<__FUNCTION__<<" : "<<__LINE__<<" #x "; FOR(i,a,b) cout<<x[i]<<" , " ; cout<<endl;
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

int bit[1000];
int n;

void add(int x,int a)
{
  int idx=x;
  while(idx<=n)
    {
      bit[idx]+=a;
      idx+=(idx&-idx);
    }
}

int get(int x)
{
  int idx=x,sum=0;
  while( idx>0 )
    {
      sum+=bit[idx];
      idx-=(idx&-idx);
    }
  return sum;
}
  


int main()
{
  int i;
  fill(bit,0);
  n=10;
  add(4,10);
  REP(i,1,n) cout<<get(i)<<"  "; cout<<endl;
  return 0;
}
