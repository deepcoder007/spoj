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

int n;
int arr[1010];
int pos[1010];
int best[1010][1010];  // best[i][j] -> making best array from i to j ( according to the final array
int bef[1010][1010];

inline void test()
{
  register int i,j,k,l;  
  n=scan();
  fill(bef,0);
  REP(i,1,n)
    arr[i]=scan();  

  REP(i,1,n)
    pos[arr[i]]=i;

  REP(i,1,n)
    best[i][i]=pos[i];
  REP(i,1,n)
    {
      bef[i][0]=0;
      REP(j,1,n)
	{
	  bef[i][j]=bef[i][j-1];
	  if( pos[j]<pos[i] ) bef[i][j]++;
	}
    }
  int x,y;
  REP(l,2,n)  // for all combination of length of the final array 
    {
      REP(i,1,n-l+1)
	{
	  j=i+l-1;
	  
	  x=best[i+1][j]+l*(pos[i]-(bef[i][j]-bef[i][i]));
	  y=best[i][j-1]+l*(pos[j]-(bef[j][j-1]-bef[j][i-1]));
	  if( x<y ) best[i][j]=x;
	  else best[i][j]=y;
	}
    }
  cout<<best[1][n]<<endl;
}


int main()
{
  int t;
  t=scan();
  while(t--)
    test();
  return 0;
}
