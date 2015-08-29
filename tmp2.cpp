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
// adding and multiplying very large numbers
int size=10000 ;
int A[1000000],B[10000000];
									       

void add(int* a,int* b)
{
  int i;
  if( *b>*a ) *a=*b;  // change the number of digits
  REP(i,1,*a) a[i]+=b[i];
  ++*a;
  REP(i,1,*a) a[i+1]+=a[i]/size,a[i]%=size;
  while( !a[*a] ) --*a;
}


void mult(int* b,int x,int* a)
{
  int i;
  REP(i,1,*b) a[i]=b[i]*x;
  *a=*b+1;

  REP(i,1,*a) a[i+1]+=a[i]/size, a[i]%=size;
  while(!a[*a]) --*a;  

}

int main()
{
  fill(A,0),fill(B,0);
  *A=1;
  *(A+1)=2;
  int i,j;
  FOR(i,1,20)
    {
      mult(A,64,B),copy(B,B+(*B)+1,A);
      cout<<*A<<"  ";
      for(j=*A;j>0;j--)
	cout<<A[j];
      cout<<endl;
    }
  return 0;
}
