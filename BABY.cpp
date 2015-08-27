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
#include<cmath>
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

void printbit(int n)
{
  string str;
  while(n)
    {
      if(n%2==0)
	{  str="0"+str;	}
      else
	{  str="1"+str;	}
      n/=2;
    }
  cout<<str<<endl;
}

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
int row_i[20],col_i[20],row_o[20],col_o[20];
int tmp1,tmp2,tmp3;
int dp[600][600];

int get_dp(int mask_i,int mask_o)   
{
    cout<<__LINE__<<" : in : "; printbit(mask_i); cout<<" : out :"; printbit(mask_o);
    cout<<__LINE__<<" : in : "<<mask_i<<" : OUt : "<<mask_o<<endl;
  if( mask_i==0 && mask_o==0 ){  return 0; }
  if( dp[mask_i][mask_o] ) {  return dp[mask_i][mask_o]; }
  register int i,j;
  int mn=(int)(INT_MAX-1);
  FOR(i,0,n)
    {

      if( (mask_i & mask_o) & (1<<i) ) 
	{
	  tmp1=abs(row_i[i]-row_o[i])+get_dp((mask_i & ~(1<<i)) & ~(1<<(n+row_i[i])), (mask_o & ~(1<<i)) & ~(1<<(n+row_o[i]))) ;
	  if( tmp1>0 )
	    mn=min(mn,tmp1 );
	}

      if( (mask_i & mask_o) & (1<<(n+row_i[i]) ) )
	{
	  tmp1= abs(col_i[i]-col_o[i]) + get_dp((mask_i & ~(1<<i)) & ~(1<<(n+row_i[i])), (mask_o & ~(1<<col_o[row_i[i]])) & ~(1<<(n+row_i[i])) );
	  if( tmp1>0 )
	    mn=min(mn, tmp1 );
	}
    }
    cout<<__LINE__<<" : "<<mn<<endl;
  dp[mask_i][mask_o]=mn;
  return mn;
}


int main()
{
  register int i,j;
  while(1)
    {
      sci(n);
      fill(row_i,0);fill(col_i,0); fill(row_o,0); fill(col_o,0); fill(dp,0);
      FOR(i,0,n) 
	{
	  tmp1=scan();
	  row_i[i]=tmp1-1;
	  col_i[tmp1-1]=i;
	}
      FOR(i,0,n)
	{
	  tmp1=scan()-1;
	  row_o[i]=tmp1;
	  col_o[tmp1]=i;
	}
      // make input and output mask
      cout<<get_dp( (1<<(2*n))-1, (1<<(2*n))-1 )<<endl;

    }
  return 0;
}
