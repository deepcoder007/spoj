#include<cstdio>
//all arrays are 1 ary
// used the interval tree or predicate tree type data structure
using namespace std;

inline long int max(long int a,long int b )
{
	if( a>b ) return a;
	else return b;
}

struct no
{ long int lsum,rsum, msum; };

long int sums[50009], arr[50009];

no tree[600001];    //the nodes to handle the various cases

void init(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]= ( (no) { arr[l],arr[l],arr[l] } );
	}
	else 
	{
		init (node*2,l,(l+r)/2 );
		init (node*2+1,(l+r)/2+1,r);
		long int left=max(tree[node*2].lsum,sums[(l+r)/2]-sums[l-1]+tree[node*2+1].lsum);
		long int right=max(tree[node*2+1].rsum,sums[r]-sums[((l+r)/2)]+tree[node*2].rsum);
		long int msum=max( tree[node*2].msum, max ( tree[node*2+1].msum, tree[node*2].rsum+tree[node*2+1].lsum ) );
		tree[node]= ( (no){ left,right,msum });
	}
}

no query(int node,int a,int b, int l,int r)
{
	if( a==l && b==r ) return tree[node];
	else if( r<=(a+b)/2 ) return query(node*2,a,(a+b)/2,l,r);
	else if( l>(a+b)/2 ) return query(node*2+1,(a+b)/2+1,r,l,r);
	no left=query(node*2,a,(a+b)/2,l,(a+b)/2);
	no right=query(node*2+1,(a+b)/2+1, b, (a+b)/2+1, r);
	return ( (no) { max( left.lsum, sums[(a+b)/2]-sums[l-1]+right.lsum ),
				max( right.rsum, sums[b]-sums[(a+b)/2]+left.rsum ),
				max( left.msum, max( right.msum , left.rsum+right.lsum ) ) } );
}


int main()
{
	int N,i,j,k,q;
	scanf("%d",&N);
	sums[0]=0;
	for(i=1;i<=N;i++)
	{
		scanf("%ld",arr+i );
		sums[i]=sums[i-1]+arr[i];
	}
	init(1,1,N);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&j,&k);
		printf("%ld\n",query(1,1,N,j,k).msum);
	}
	return 0;
}






