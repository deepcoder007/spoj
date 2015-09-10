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
#include<bits/stdc++.h>
#include<iterator>
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

// using quadratic decomposition
int arr[100009];
int quad[100009];
int buf[1000];
int n,q,root;
int tmp1,tmp2,tmp3;

int main()
{
  register int i,j;
  sc2i(n,q);
  FOR(i,0,n) sci(arr[i]);
  copy(arr,arr+n,quad);
  root=sqrt(n);  // the block size of every element
  for(i=0;i<n;i+=root)
      sort(quad+i,quad+min(n,i+root));
  char c;
  int res,len,l1,r1,mid;
  while(q--)
    {
      cin>>c;
      if( c=='M' )
	{
	  sc2i(tmp1,tmp2);
	  arr[tmp1-1]=tmp2;
	  tmp3=(int)(tmp1/root);
	  tmp3*=root;
	  //	  for(tmp3=0;tmp3<(tmp1);tmp3+=root); tmp3-=root;
	  copy(arr+tmp3,arr+tmp3+root,quad+tmp3);
	  sort(quad+tmp3,quad+min(n,tmp3+root));
	}
      else // the query one
	{
	  sc2i(tmp1,tmp2),sci(tmp3);
	  int l,r;
	  res=0;
	  l=(int)(tmp1/root),l*=root; r=(int)(tmp2/root) , r*=root;
	  // add the result of first and last sets
	  copy(arr+tmp1-1,arr+l+root,buff);
	  len=l+root-tmp1+1;
	  sort(buff,buff+len);
	  l1=0,r1=len-1;
	  mid=(l1+r1)>>1;
	  while( buff[mid]<=v )
	    {
	      l1=mid+1;
	    }
	  else
	    {
	      r1=mid;
	    }


	}
  return 0;
}
  


