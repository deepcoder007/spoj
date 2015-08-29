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
#define trace3(x,y,z) cout<<__FUNCTION__<<" : "<<__LINE__<<" #x "<<x<<" #y "<<y<<" #z "<<z<<endl
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
int arr[20009];
int farr[20009];
int T[100000];   // the segment tree
int k,n,t;

// the 1-ary array but the bounds are inclusive
void init(int n,int l,int r) 
{
  if( l==r ) 
    {
      T[n]=arr[l];
      return;
    }
  if( l>r ) return ;
  int mid=l+(r-l)/2;
  init(n*2,l,mid);
  init(n*2+1,mid+1,r);
  T[n]= T[n*2] & T[n*2+1];
}

// [x,y] specifies the range in which we want to query
int query(int n,int l,int r,int x,int y)
{
  if( l==x && r==y ) return T[n]; // the current node is within the range
  if( y<l || x>r ) return -1;   // out of range

  int mid=l+(r-l)/2;
  //    trace3(n,l,r); cin>>t;
  if( y<= mid ) return query(n*2,l,mid,x,y);
  if( x> mid ) return query(n*2+1,mid+1,r,x,y);
  else return query(n*2,l,mid,x,mid) & query(n*2+1,mid+1,r,mid+1,y);
  
}



int main()
{
  register int i,j;
  sci(t);
  while(t--)
    {
      sc2i(n,k);
      FOR(i,0,n)
	sci(arr[i]);
      k=min(k,n-1);
	
	  // apply the segment tree
	  init(1,0,n-1);
	  int tmp1,tmp2,tmp3;
	  int res=-1;
	  int s,e;
	  FOR(i,0,n)   // apply this technique segment wise
	    {

	      s=(i-k+n)%n;
	      e=(i+k)%n;
	      res=-1;

	      if( s<i ) res&= query(1,0,n-1,s,i);
	      else res&= query(1,0,n-1,0,i) & query(1,0,n-1,s,n-1);

	      if( e>i ) res&= query(1,0,n-1,i,e);
	      else res&= query(1,0,n-1,i,n-1) & query(1,0,n-1,0,e);

	      farr[i]=res;
	    }

      FOR(i,0,n)
	cout<<farr[i]<<" ";
      cout<<endl;
    }
  return 0;
}
      

