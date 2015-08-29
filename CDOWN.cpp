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

int rgraph[10000];    // the map from child to parent
int COUNT[10000];  
//map<int,set<int> >  graph;    // the map from parent to all its children
map<string,int> nmap ;   // mapping name to the index
map<int,string> rev_nmap;   // map the index to the name
set<string> ppls;      // the set of found people
set<string>::iterator sit ;   // the iterator for the set

struct ps
{
  int count;
  int idx;
};

bool ps_compare(ps lhs,ps rhs ) { return lhs.count > rhs.count ; }

int main()
{
  ps pstruct[10000];
  register int i,j;
  int t,tcount=1;
  string stmp1,stmp2,stmp3;
  int tmp1,tmp2,tmp3,idx;
  int tt;
  int c;  
  sci(tt);
  while(tt--)
    {
      //      cout<<"New test case : "<<endl;
      idx=0;
      fill(rgraph,-1);
      //      graph.clear();
  nmap.clear();  rev_nmap.clear();   ppls.clear();
      sc2i(c,t);
      while(c--)
	{
	  cin>>stmp1;
	  if( ppls.find(stmp1)==ppls.end() )  // i.e. not found
	    {
	      ppls.insert(stmp1);
	      nmap[stmp1]=idx;
	      rev_nmap[idx]=stmp1;
	      //	      graph[idx]=set<int>();
	      idx++;
	    }
	  cin>>tmp1;   // the count of what to follow
	  //	  cout<<"read edges from : "<<stmp1<<endl;
	  while( tmp1-- )   
	    {
	      cin>>stmp2;
	      if( ppls.find(stmp2)==ppls.end() )
		{
		  ppls.insert(stmp2);
		  nmap[stmp2]=idx;
		  rev_nmap[idx]=stmp2;
		  idx++;
		}
	      rgraph[nmap[stmp2]]=nmap[stmp1];
	      //	      cout<<"   the child : "<<stmp2<<" : "<<nmap[stmp2]<<" : "<<nmap[stmp1]<<endl;
	    }

	}
     // input complete now start the count
      // debug
      /*            cout<<"total people identified : "<<idx<<endl;
	    cout<<"list of edges :"<<endl;
	    FOR(i,0,idx)
	      if( rgraph[i]>0 )  // if there is a parent
		cout<<rev_nmap[i]<<"  : to : "<<rev_nmap[rgraph[i]]<<endl;
      */
      fill(COUNT,0);
      if( t==1 )  // i.e. count the parents
	{
	  FOR(i,0,idx)
	    {
	      if( rgraph[i]>=0 )  COUNT[rgraph[i]]++; 
	    }
	}
      else if( t==2 )
	{
	  FOR(i,0,idx)
	    {
	      if( rgraph[i]>=0 && rgraph[rgraph[i]] >=0 ) COUNT[rgraph[rgraph[i]]]++;
	    }
	}
      FOR(i,0,idx)
	{
	  pstruct[i].idx=i;
	  pstruct[i].count=COUNT[i];
	}
      sort(pstruct,pstruct+idx,ps_compare);
      // the first 3 are in our category
      printf("Tree %d:\n",tcount);
      //      cout<<"Tree "<<tcount<<endl;
      /**
      FOR(i,0,3)
	{
	  if( i<idx )
	    {
	      cout<<rev_nmap[pstruct[i].idx]<<" "<<pstruct[i].count<<endl;
	    }
	}
      **/
      int outcount=0;   
      int curr_idx=0;  // the pstruct to consider next
      int curr_cnt;
      set<string> the_set;   // the set holding the similar 
      while(1)
	{
	  curr_cnt=pstruct[curr_idx].count;
	  if( curr_cnt== 0 ) break;  // no need to print
	  the_set.clear();
	  while(pstruct[curr_idx].count==curr_cnt)
	    {
	      the_set.insert(rev_nmap[pstruct[curr_idx].idx]);
	      curr_idx++;
	    }
	  outcount+=the_set.size();  
	  for(sit=the_set.begin();sit!=the_set.end();sit++)
	    {
	      printf("%s %d\n",(*sit).c_str(),curr_cnt);
	      //	      cout<<*sit<<" "<<curr_cnt<<endl;
	    }
	  if( outcount>=3 )
	    break;
	}
      tcount++;
    }
  return 0;
}
