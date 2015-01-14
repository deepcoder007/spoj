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

long int dp[105][105][2];

void init()
{
	memset(dp,0,sizeof(dp));
	register int i,j,k;
	dp[1][0][0]=dp[1][0][1]=0;
	dp[2][0][0]=2; dp[2][0][1]=1;
	dp[2][1][0]=0;     dp[2][1][1]=1;

	for(i=3; i<=100; i++)  // for all the length of the strings
	{
		for( j=0; j<i ; j++ )
		{
			dp[i][j][1]= dp[i-1][j][0] + dp[i-1][j-1][1];
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
		}
	}
}

int main()
{
	init();
	int i,j,k;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&i,&j,&k);
		printf("%d %ld\n",i, dp[j][k][0] + dp[j][k][1]);
	}
	return 0;
}



