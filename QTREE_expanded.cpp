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

// A tough problem
//------------------------------------------------------------
// Global variable  space
typedef pair< pii ,int>  we;    // the weighted edge
int n;
int rg[10010];    // the reverse graph
map<int,VI > g ;    // to store the graph
we edges;    // to store all the edges
map<int,pii> edges_idx;   // index of the edges
int idx;   
map<int,VI > paths_el;   // the edge length of the path
map<int,VI > paths ;    // ele 2.  -> the paths
VI path_head;     // ele 1. -> the path heads
map<int,int> path_count;   // ele 3. -> the size of paths
int child_count[10010];     // the count of the number of child
int path_pos[10010];     // ele 4.  -> the pos of the current element in path
int curr_head[10010];    // ele 5.  -> the head of the current element
int height[10010];     // the distance of the current node from root

map<int,vector<int> >  segT;    // the segment tree of the individual path
int head_idx;
// NOTE: 1. paths are recognized by path head
// 2. the query is to find the maximum edge cost
// 3. segment tree is on the length of the path
//----------------------------------------------------------------------------------------------------

int get_lca(int a,int b)   // the index of lowest common ancestor of a,b
{
  VI va,vb;
  int i,j;
  i=a; 
  while(i!=-1)
    {
      va.pb(i); 
      i=rg[i] ;
    }
  i=b; 
  while(i!=-1)
    { 
      vb.pb(i);
      i=rg[i] ;
    }
  i=va[va.size()-1];
  j=vb[vb.size()-1];
  while( va[i]==vb[j] ) i--,j--; 
 i++,j++;
 return i;
}

// l,r -> CAUTION: they are index
void init(int p,int tt,int l,int r)   // p -> the path head
{
  if( l==r ) segT[p][tt]=paths_el[p][l];
  int mid=(l+r)>>1;
  init(p,tt<<1,l,mid);
  init(p,(tt<<1)|1,mid+1,r);
  segT[p][tt]=max(segT[p][tt<<1],segT[p][(tt<<1)|1]);
}

// l,r,x,y -> they are index
int query(int p,int tt,int l,int r,int x,int y)  // x,y -> the range of query
{
  if( l>r ) return 0;
  if(x==l && y==r) return segT[p][tt];
  int mid=(l+r)>>1;
  if( y<=mid ) return query(p,tt<<1,l,mid,x,y);
  else if( x>mid ) return query(p,(tt<<1)|1,mid+1,r,x,y);
  else return max(query(p,(tt<<1),l,mid,x,mid),query(p,(tt<1)|1,mid+1,r,mid+1,y) );
}

update(int p,int tt,int l,int r,int x,int a)  // update the x'th element to a
{
  if( l==r && x==a ) segT[p][tt]=a;
  int mid=(l+r)>>1;
  if( x<=mid ) update(p,tt<<1,l,mid,x,a) ;
  else if( x>mid ) update(p,(tt<<1)|1,mid+1,r,x,a);
  segT[p][tt]=max(segT[p][tt<<1],segT[p][(tt<<1)|1]) ;
}
  
inline void test()
{
  sci(n);
  int i,j;
  int t1,t2,t3,tmp1,tmp2,tmp3; 
  idx=0; 
  fill(rg,-1); 
  edges.clear(); 
  fill(child_count,0); 
  paths.clear();
  path_head.clear(); 
  path_count.clear(); 
  fill(path_pos,-1);
  fill(curr_head,-1);
  fill(height,-1);
  REP(i,1,n) 
    g[i]=VI();
  FOR(i,1,n)
    {
      sc2i(t1,t2);  sci(t3);
      g[t1].pb(t2);
      edges.pb(mp(mp(t1,t2),t3));
      edges_idx[++idx]=mp(t1,t2);   
      rg[t2]=t1;  
      child_count[t1]++;  
    }
  // now initialize the data structures
  REP(i,1,n)  
    if(rg[i]!=-1) 
      head_idx=i,break;   // find the head of the tree
  rg[head_idx]=head_idx; 
  edges.pb(mp(mp(head_idx,head_idx),0)); 

  // find the paths
  queue<int> q;  // the head of bfs
  q.insert(head_idx); 
  height[head_idx]=0;
  int mx,mxi;
  VI::iterator vit;
  while( !q.empty() )
    {
      tmp1=q.front();
      q.pop(); mx=0;
      if( curr_head[tmp1]==-1 ) path_head.pb(tmp1),curr_head[tmp1]=tmp1, path_pos[tmp1]=0 ,path_count[tmp1]=1, paths[tmp1]=VI(),paths[tmp1].pb(tmp1),paths_el[tmp1]=VI(),paths_el[tmp1].pb(edges[mp(rg[tmp1],tmp1)]) ;
      else path_pos[tmp1]=path_count[curr_head[tmp1]] , path_count[curr_head[tmp1]]++ , paths[curr_head[tmp1]].pb(tmp1), paths_el[curr_head[tmp1]].pb(edges[mp(rg[tmp1],tmp1)]);
      
      for(vit=g[tmp1].begin();vit!=g[tmp1].end();vit++)
	{
	  q.push(*vit),height[*vit]=height[tmp1]+1; 
	  if( child_count[*vit] > mx )  mxi=*vit , mx=child_count[*vit] ;
	}
      curr_head[mxi]=curr_head[tmp1];   // the highest index one is added to the path
      
    }

  // initialize the segment tree 
  FOR(i,path_head.size()) segT[path_head[i]]=VI(paths[path_head[i]].size()*4,0) , init(path_head[i],1,0,paths_el[path_head[i]].size()-1);
  
  // now start the Queries
  string stmp; 
  while(1)
    {
      cin>>stmp;
      if( stmp[0]=='D' ) break;  // "DONE"
      cin>>t1>>t2;
      if( stmp[0]=='C' )  // change 
	{
	  pii edt=edges_idx[t1];
	  update( curr_head[edt.second],1,0,paths_el[curr_head[edt.second]].size()-1,path_pos[edt.second],t2);
	  edges[edt]=t2;
	}
      else if(stmp[0]=='Q' )  // the query of the max -> the complicated step
	{
	  t3=lca(t1,t2);  
	  if( t3==t1 )   // i.e. t1 is higher in the hierarchy
	    {
	      int ans=0;
	      while( curr_head[t2]!=curr_head[t1] )
		{
		  ans=max(ans,query(curr_head[t2],1,0,paths_el[curr_head[t2]].size()-1,0,path_pos[t2]));
		  t2=rg[curr_head[t2]];  // the last node of the chain above
		}
	      ans=max(ans,query(curr_head[t1],1,0,paths_el[curr_head[t2]].size()-1, path_pos[t1]+1,path_pos[t2] ));
	      cout<<ans<<endl;
	    }
	  else if( t3==t2)
	    {
	      int ans=0;
	      while( curr_head[t1]!=curr_head[t2] )
		{
		  ans=max(ans,query(curr_head[t1],1,0,paths_el[curr_head[t1]].size()-1,0,path_pos[t1]));
		  t1=rg[curr_head[t1]];
		}
	      ans=max(ans,query(curr_head[t2],1,0,paths_el[curr_head[t1]].size()-1,path_pos[t2]+1,path_pos[t1] ));
	      cout<<ans<<endl;
	    }
	  else   // if they have a common ancestor 
	    {
	      int ans1=0,ans2=0;
	      while( curr_head[t2]!=curr_head[t3] )
		{
		  ans1=max(ans1,query(curr_head[t2],1,0,paths_el[curr_head[t2]].size()-1,0,path_pos[t2]));
		  t2=rg[curr_head[t2]];
		}
	      ans1=max(ans1,query(curr_head[t3],1,0,paths_el[curr_head[t2]].size()-1,path_pos[t3]+1,path_pos[t2] ));
	      
	      while( curr_head[t1]!=curr_head[t3] )
		{
		  ans2=max(ans2,query(curr_head[t1],1,0,paths_el[curr_head[t1]].size()-1,0,path_pos[t1]));
		  t1=rg[curr_head[t1]];
		}
	      ans2=max(ans2,query(curr_head[t2],1,0,paths_el[curr_head[t2]].size()-1,path_pos[t3]+1,path_pos[t1] ));
	      cout<<max(ans1,ans2)<<endl;
	    }
	}
    }
}

int main()
{
  int t;
  sci(t);
  while(t--)
    test();
  return 0;
}
