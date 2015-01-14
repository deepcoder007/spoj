#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<functional>
#include<map>
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


struct intv
{
	int start;
	int end;
	bool operator < ( intv a) const
	{
		return end < a.end;
	}
};

intv data[100009];
int dp[1000009];    // stores the starting point of the current array
int n;
int curr;
int cnt;


inline void test()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	register int i;
	for(i=0;i<n;i++)
		scanf("%d%d",&data[i].start, &data[i].end );
	sort( data, data+n );
	for(i=0;i<n;i++)
	{
		dp [ data[i].end ] = max ( dp [data[i].end ] , data[i].start );
	}
	cnt =0;
	curr =0;
	for(i=0; i<n; i++)
	{
		if( curr <= dp[ data[i].end ] )
		{
			curr = data[i].end ;
			cnt++;
		}
	}
	cout<<cnt<<endl;


}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
