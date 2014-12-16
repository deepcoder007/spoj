#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;

int max(int a,int b)
{
	if( a> b) return a;
	else return b;
}

inline int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int e,f;  // e = weight of the piggy bank, f=weight filled with coins
int n;
int W[501]; // the weight of the coins
int P[501];  // the value of the coins

int dp[10001];   

inline void test()
{
	register int i,j;
	scanf("%d%d",&e,&f);
	f-=e;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&P[i],&W[i]);
	//input over
	memset(dp,-1,sizeof(dp));
	dp[0]=0;    // the base case
	for(i=1;i<=f;i++)     // for all values of weight
	{
		for(j=0;j<n;j++)   // over all the products
		{
			if( W[j]<=i && dp[i-W[j]]!=-1 )
			{
				if(dp[i]!=-1) dp[i]=min(dp[i],dp[i-W[j]]+P[j]);
				else dp[i]=dp[i-W[j]]+P[j];
			}
		}
	}
	if(dp[f]==-1)
		printf("This is impossible.\n");
	else
		printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
