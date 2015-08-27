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
#define tracea(x,a,b,i) cout<<__FUNCTION__<<" : "<<__LINE__<<" #x = "; FOR(i,a,b) cout<<x[i]<<" , " ; cout<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int ui;
typedef long double ld;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
/*
inline int min(int a,int b)
{
	if( a< b ) return a;
	else return b;
}

inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}
*/
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

ll C[2010];
ll V[2010];
ll dp[2010][2010];
int s,n;

int main()
{
  register int i,j;
  cin>>s>>n;
  REP(i,1,n) cin>>C[i]>>V[i];
  // now start the dp
  FOR(i,0,s) dp[0][i]=0;
  FOR(i,0,n) dp[i][0]=0;
  REP(i,1,n)  // for all the items
    {
      REP(j,1,s)  // for all the weigths
	{
	  if( C[i]>j )
	    {
	      dp[i][j]=dp[i-1][j];
	    }
	  else
	    {
	      dp[i][j]=max(dp[i-1][j],dp[i-1][j-C[i]]+V[i]);
	    }
	}
    }
  /* debug mode */
  /*
  cout<<"DEBUG"<<endl;
  REP(i,0,n)
    {
      tracea(dp[i],0,s,j);
    }
  */
  /* debug end */
    cout<<dp[n][s]<<endl;
    return 0;
}
  

