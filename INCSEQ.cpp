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
int n,k;
int arr[10010];
int dp[10010][55]; // dp[i][j] -> number of seq of length j using elements 1..i 


int main()
{
  register int i,j;
  sc2i(n,k);
  FOR(i,0,n) sci(arr[i+1]);
  fill(dp,0);
  dp[1][0]=0 , dp[1][1]=1;
  REP(i,1,n)
    {
      REP(j,1,k)
	{
	  


	} 
    }

