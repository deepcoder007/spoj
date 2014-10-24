#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;

int pl[11][11], dp[11][1<<11];

inline int max(int a,int b)
{
	if( a>=b ) return a;
	else return b;
} 

int solve(int pos,int mask )  // pos is the current position, mask is the set of players that is already used
{
	if(pos==11)
	{
		if(mask== (1<<11)-1) return 0;
		else return INT_MIN;
	}
	if(dp[pos][mask]>-1 ) return dp[pos][mask];
	int& ret=dp[pos][mask]; ret= INT_MIN;
	int tmp;
	int i;
	for(i=0; i<11; i++)
	{
		if(pl[i][pos] &&  !(mask&(1<<i)) )
		{
			tmp=pl[i][pos]+solve(pos+1,mask|(1<<i));
			ret=max(tmp,ret);
		}
	}
	return ret;
}

inline void test()
{
	register int i,j;
	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
			cin>>pl[i][j];
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0)<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}

