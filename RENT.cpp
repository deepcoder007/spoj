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
using namespace std;

inline int min(int a,int b)
{
	if( a< b ) return a;
	else return b;
}

inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

struct node
{
	int start;
	int end;
	int cost;
};

bool sort_code(const node &a,const node &b ){ return a.end < b.end ; }
int mx,n; 
node nd[10000];
int dp[2000009]; // for storing the cost

void test()
{
  //  cout<<"Inside test"<<endl;
	memset(nd,0,sizeof(node)*10000);
	memset(dp,0,sizeof(int)*2000009); 
	//input the data
	scanf("%d",&n);
	register int i,j,k;
	for( i = 0 ; i < n; i++)
	  {
	    scanf("%d",&nd[i].start);
	    scanf("%d",&nd[i].end);
	    scanf("%d",&nd[i].cost);
	    mx= max(mx,nd[i].end);
	  }
	sort(nd ,nd+n,sort_code);
	for( i=0 ,j=0 ; i<mx; i++) // i is every step, j is the interval idx
	  {
	    while( j<n && i==nd[j].start)
	      {
		dp[nd[j].end]=max(dp[nd[j].end],dp[nd[j].start]+nd[j].cost);
		j++;
	      }
	    dp[i+1]=max(dp[i],dp[i+1]);
	  }
	printf("%d\n",dp[mx]);

}

int main()
{
	int t;
	scanf("%d",&t);
	while( t-- )
		test();
	return 0;
}	
