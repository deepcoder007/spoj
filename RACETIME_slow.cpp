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

// a implementation intensive question of segment tree
int n,q;
ll A[100009];
ll* T[600009];

void init(int n,int l,int r)
{
  if(l==r) { T[n]=new ll[1], T[n][0]=A[l]; return; }
  int mid=(l+r)>>1,c=n<<1;
  init(c,l,mid);
  init(c|1,mid+1,r);
  T[n]=new ll[r-l+1];
  // now merge T[c], T[c|1] to T[n]
  register int i=0,j=0,k=0;
  int l1=(mid-l+1),l2=(r-mid);
  while( j<l1 || k<l2 ) 
    {
      if( j<l1 && k<l2 && T[c][j]<=T[c|1][k] )	  T[n][i++]=T[c][j++];
      else if( j<l1 && k<l2 && T[c][j]>T[c|1][k] )  T[n][i++]=T[c|1][k++];
      else if( j==l1 )  while( k<l2 ) T[n][i++]=T[c|1][k++];
      else if( k==l2 )  while( j<l1 ) T[n][i++]=T[c][j++];
    }
}

void update(int n,int l,int r,int x,int v) 
{
  if( x<l || x>r ) return;  // out of range
  if( l==r && x==l ) { T[n][0]=v;return ; }
  int mid=(l+r)>>1,c=n<<1;
  update(c,l,mid,x,v);
  update(c|1,mid+1,r,x,v);
  // now remerge T[c], T[c|1] to T[n]
  register int i=0,j=0,k=0;
  int l1=(mid-l+1),l2=(r-mid);
  while( j<l1 || k<l2 )
    {
      if( j<l1 && k<l2 && T[c][j]<=T[c|1][k] ) T[n][i++]=T[c][j++];
      else if( j<l1 && k<l2 && T[c][j]>T[c|1][k] ) T[n][i++]=T[c|1][k++];
      else if( j==l1 ) while( k<l2 ) T[n][i++]=T[c|1][k++];
      else if( k==l2 ) while( j<l1 ) T[n][i++]=T[c][j++];
    }
}

int query(int n,int l,int r,int x,int y,int v)  // find the no. of elements <=v 
{
  register int i,j;int mid,c;
  if(l==x && r==y ) 
    {
      r-=l,y-=l,x=0,l=0;
      if( T[n][r]<=v ) return r+1;
      // use binary search to find the element
      while( l<r )
	{
	  mid=(l+r)>>1;
	  if( T[n][mid]<=v )   l=mid+1;
	  else    r=mid;
	}
      return l;
    }
  mid=(l+r)>>1,c=n<<1;
  if( y<=mid )  return query(c,l,mid,x,y,v);
  else if( x>mid ) return query(c|1,mid+1,r,x,y,v);
  else return ( query(c,l,mid,x,mid,v)+query(c|1,mid+1,r,mid+1,y,v) );
}


int main()
{
  int tmp1,tmp2,tmp3;
  register int i,j;
  sc2i(n,q);
  FOR(i,0,n) scanf("%lld",&A[i]);
  init(1,0,n-1);
  char c;
  while(q--)
    {
      cin>>c;
      if( c=='M' )
	{
	  sc2i(tmp1,tmp2);
	  update(1,0,n-1,tmp1-1,tmp2);
	}
      else
	{
	  sc2i(tmp1,tmp2),sci(tmp3);
	  cout<<query(1,0,n-1,tmp1-1,tmp2-1,tmp3)<<endl;
	}
    }
  return 0;
}
