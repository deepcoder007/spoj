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
int n,m;
int arr[300][300];
int T[3000][3000];  

bool check(int x1,int y1,int x2,int y2,int v)  // checks if the sum is <=v
{
  int sum=0;
  register int i,j;
  REP(i,x1,x2) REP(j,y1,y2) sum+=arr[i][j];
  if( sum<=v ) return true; else return false;
}

// no. of matrix with sum of elements <=v
void init(int n1,int n2,int l1,int l2,int r1,int r2,int v) // coordinates are (l1,l2) , (r1,r2) 
{
  if( l1>r1 || l2>r2 ) return ;
  if(l1==r1 && l2==r2) { if(arr[l1][l2]<=v) T[n1][n2]=1; return; }
  int mid1=(l1+r1)>>1,mid2=(l2+r2)>>1;
  int c1=n1<<1,c2=n2<<1;
  trace2(n1,n2); 
  trace2(l1,l2); 
  trace2(r1,r2);
  cout<<endl;
  init(c1,c2,l1,l2,mid1,mid2,v);
  init(c1,c2|1,l1,mid2+1,mid1,r2,v);
  init(c1|1,c2,mid1+1,l2,r1,mid2,v);
  init(c1|1,c2|1,mid1+1,mid2+1,r1,r2,v);
  T[n1][n2]=T[c1][c2]+T[c1|1][c2]+T[c1][c2|1]+T[c1|1][c2|1];
  register int i,j,k,l;
  REP(i,l1,mid1) REP(j,l2,mid2) REP(k,i+1,n) REP(l,j+1,m) T[n1][n2]+=check(i,j,k,l,v);
}

int main()
{
  register int i,j;
  sc2i(n,m);
  REP(i,1,n) REP(j,1,m) sci(arr[i][j]);
  fill(T,0);
  int a,b;
  sc2i(a,b);
  trace2(a,b);
  init(1,1,0,0,n-1,m-1,b);
  int ans=T[1][1];
  trace(ans);
  init(1,1,0,0,n-1,m-1,a-1);
  ans-=T[1][1];
  cout<<ans<<endl;
  return 0;
}

