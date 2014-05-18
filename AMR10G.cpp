#include<cstdio>
#include<climits>
#include<algorithm>
#include<functional>
using namespace std;

int arr[20010];
int ai,bi;

inline int min(int a,int b)
{
	if( a> b) return b;
	else return a;
}


inline void test()
{
	int n,k;
	int mi=INT_MAX;
	scanf("%d %d",&n,&k);
        ai=0; bi=k-1;	
	register int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for( i=0 ; i<=(n-k) ;i++)
	{
		mi=min(mi, arr[i+k-1]-arr[i] );
	}
	printf("%d\n",mi);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
