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

int n;
string st1[100009];
string st2[100009];
int pos1[100009];   // pos1[i]=j  => i'th element is at point j in st1 => order to element mapping
int pos2[100009];
int idx1[100009];   // idx1[i]=j  => i'th element in st1 is at point j in final seq  => element to order mapping 
int idx2[100009];
int bit[100009];

void add(int x,int a)
{
  int idx=x;
  while(idx<=n)    {   bit[idx]+=a;      idx+=(idx&-idx);    }
}

int get(int x)
{
  int idx=x,sum=0;
  while( idx>0 )    { sum+=bit[idx]; idx-=(idx&-idx);    }
  return sum;
}

bool cmp1(int i,int j) 
{ return st1[i]<st1[j];   }

bool cmp2(int i,int j)
{ return st2[i]<st2[j];   }

int main()
{
  register int i,j;
  sci(n);
  FOR(i,0,n) cin>>st1[i], st2[i]=st1[i], reverse(st2[i].begin(),st2[i].end()), pos1[i]=i, pos2[i]=i; 
  sort(pos1,pos1+n,cmp1);
  sort(pos2,pos2+n,cmp2);
  FOR(i,0,n) idx1[pos1[i]]=i , idx2[pos2[i]]=i;  

  FOR(i,0,n) add(i+1,1);
  ll ans=0;

  FOR(i,0,n)
    {
      ans+=(get(idx2[pos1[i]]+1)-1);
      add(idx2[pos1[i]]+1,-1);
    }
  cout<<ans<<endl;
  return 0;
}
