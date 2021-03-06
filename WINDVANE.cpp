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
// use the 2-d segement tree
// +1 -> clockwise , -1 -> anti-clockwise
// often implementing stack and queue via array can be faster and better 
int m,n;
int arr[1010][1010];
ll bit[1010][1010];
map<char,int> smap;
map<int,char> rsmap;

void add(int k,int idx ,int val){
    while (idx <= n){
        bit[k][idx] += val;
        idx += (idx & -idx);
    }
}

int read(int k,int idx){
    int sum = 0;
    while (idx > 0){
        sum += bit[k][idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
  fill(bit,0),fill(arr,0);
  string stmp;char ci; int x1,y1,x2,y2,t,tmp1,tmp2;
  register int i,j;
  smap['N']=0,smap['E']=1,smap['S']=2,smap['W']=3;
  rsmap[0]='N',rsmap[1]='E',rsmap[2]='S',rsmap[3]='W';
  sc2i(m,n);
  FOR(i,0,m)
    {
      cin>>stmp;
      FOR(j,0,n)
	arr[i+1][j+1]=smap[stmp[j]];
    }
  // the array are 1-ary
  sci(t);
  while(t--)
    {
      cin>>ci;
      if(ci=='D')
	{
	  sc2i(x1,y1);
	  x2=arr[x1][y1]+read(x1,y1);
	  cout<<rsmap[x2%4]<<endl;
	}
      else if( ci=='C' )
	{
	  sc2i(x1,y1),sc2i(x2,y2),sci(tmp1);
	  REP(i,x1,x2)
	    if( tmp1==0 )   // i.e. clockwise
	      {  
		add(i,y1,1), add(i,y2+1,-1);
	      }
	    else if( tmp1==1 )  // i.e. anticlockwise
	      {
		add(i,y1,-1), add(i,y2+1,+1);
	      }
	}
    }
  return 0;
}    

