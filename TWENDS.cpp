#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
int arr[1001];

// stores the max possible difference
int dp[1001][1001];     // stores the max 

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int t1,t2;

int dps(int x,int y)    // the optimal score between x and y [both points inclusive]
{
	if( y<x ) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	register int i,j;
	// take left -> arr[ (x+1) .. y ]
	if(arr[x+1] > arr[y] )   // greedy also takes the left
	{
		dps(x+2,y);
		t1=dp[x+2][y]-arr[x+1]+arr[x];
	}
	else  // greedy takes right
	{
		dps(x+1,y-1);
		t1=dp[x+1][y-1]-arr[y]+arr[x];
	}
	// take right -> arr[ x...(y-1) ]
	if( arr[x] > arr[y-1] )   // greedy takes left
	{
		t2=dp[x+1][y-1]+arr[y]-arr[x];
	}
	else    // greedy takes right
	{
		dps(x,y-2);
		t2=dp[x][y-2]+arr[y]-arr[y-1];
	}
	dp[x][y]=max(t1,t2);
	return dp[x][y];
}

int main()
{
	register int i,j;
	int sum;
	j=0;
	while(1)
	{
		j++;
		scanf("%d",&n);
		if(n==0) return 0;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		// input complete ---- now start the processing
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
			dp[i][i]=arr[i];
		for(i=1;i<n;i++)
		{ dp[i-1][i]= (arr[i-1]<arr[i])?arr[i]-arr[i-1]:arr[i-1]-arr[i]  ; }
		dps(0,n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",j,dp[0][n-1]);
	}
	return 0;
}



