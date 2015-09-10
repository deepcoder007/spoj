#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<stack>
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

// quite ambitious problem -> a very complicated hld
// NOTE: all the nodes are black initially


int tmp1,tmp2,tmp3;
int n,t,u,idx;
bool base[100009];   // base[i] is false if colour of i'th element in black
int base_idx;
int chain_idx[100009];   // the chain to which node belongs
int pos[100009];    // pos[i]= the position of node i in base
int rev_pos[100009];    // rev_pos[i]=the node id of pos i in base
bool black[500000],white[500000];   // the segment tree
int chain_start[100009];    // the start index of chain in base
int chain_end[100009];    // the end index of chain in base


int p[100009];   // the parent of node
int size[100009];   // the size of the subtree of this node
VI g[100009]; // the storing of the graph
bool visited[100009];

void init(int n,int l,int r)
{
  if( l==r ) if( base[l]==0 ) black[n]=true,white[n]=false; else black[n]=false, white[n]=true;
  int mid=(l+r)>>1;
  int c=n<<1;
  init(c,l,mid);
  init(c|1,mid+1,r);
  if( black[c] && black[c|1] )  black[n]=true ; else black[n]=false;
  if( white[c] && white[c|1] )  white[n]=true ; else white[n]=false;
}

int query_black(int n,int l,int r,int x,int y) // (x,y) is the query range
{
  if( y<x ) return 0;
  if(l==x && r==y) 
    if( black[n] ) return (r-l+1);
    else if( white[n] ) return 0;
  int mid=(l+r)>>1;
  int c=n<<1;
  if( y<=mid )
    return query_black(c,l,mid,x,y);
  else if( x>mid )
    return query_black(c|1,mid+1,r,x,y);
  else return (query_black(c,l,mid,x,mid)+query_black(c|1,mid+1,r,mid+1,y));
}

int query_white(int n,int l,int r,int x,int y)
{
  if( y<x ) return 0;
  if(l==x && r==y )
    if( white[n] ) return (r-l+1);
    else if( black[n] ) return 0;
  int mid=(l+r)>>1;
  int c=n<<1;
  if( y<=mid )
    return query_white(c,l,mid,x,y);
  else if( x>mid )
    return query_white(c|1,mid+1,r,x,y);
  else return (query_white(c,l,mid,x,mid)+query_white(c|1,mid+1,r,mid+1,y));
}

int get_same_color(int k)  // no. of nodes having same color as k
{
  int res=0;  
  bool col=base[pos[k]];  // the color of the node
  int l,r;
  queue<pair<int,pii > > q;  // the queue of trees
  q.push( mp(chain_idx[k],mp(chain_start[chain_idx[k]],chain_end[chain_idx[k]])) );
  pair<int,pii > el;
  while( !q.empty() )
    {
      el=q.front();
      q.pop();
      if( col==false ) // test for black color
	{
	  tmp3=query_black(1,0,base_idx-1,


    }


}

void hld(int k) // start the heavy light decomposition at the node pointed out
{
  if( chain_idx[k]==-1 )  // start a new chain
    {
      chain_idx[k]=idx; 
      chain_start[idx]=base_idx;
      idx++;   // change to next chain
    }
  register int i,j;
  pos[k]=base_idx;
  rev_pos[base_idx++]=k;

  if( g[k].size()==0 ) { chain_end[idx-1]=base_idx-1; return; } // no child nodes

  // find the biggest subtree of this tree
  int sub_idx=g[k][0];   
  FOR(i,1,g[k].size()) if( size[g[k][i]]>size[sub_idx] ) sub_idx=g[k][i];
  chain_idx[sub_idx]=chain_idx[k];
  hld(sub_idx);
  
  // now call hld for all other nodes
  FOR(i,0,g[k].size())  if( g[k][i]!=sub_idx ) hld(g[k][i]);
}

void dfs()  // calculates teh size also at the same time
{
  register int i,j;
  fill(p,-1);  p[1]=0; fill(visited,0); visited[1]=true; 
  REP(i,0,n)  size[i]=1;  
  stack<int> st,st2;  st.push(1); 
  while( !st.empty() )
    {
      tmp1=st.top(); st.pop(); st2.push(tmp1);
      FOR(i,0,g[tmp1].size())
	  if( !visited[g[tmp1][i]] )
	      visited[g[tmp1][i]]=true, p[g[tmp1][i]]=tmp1, st.push(g[tmp1][i]);
    }
  while( !st2.empty() )
      tmp1=st2.top(),  st2.pop(),   size[p[tmp1]]+=size[tmp1];
}

int main()
{
  register int i,j;
  sci(n);
  i=n-1;
  while( i-- )
    {
      sc2i(tmp1,tmp2);
      g[tmp1].pb(tmp2);
      g[tmp2].pb(tmp1);
    }
  // now start the preprocessing
  dfs();
  base_idx=0,idx=1;   // the first chain is tagged 1
  fill(base,0);fill(chain_idx,-1);
  hld(1);   // start hld at node "1"
  init(1,0,base_idx-1);  // for all the elements in the array

}
