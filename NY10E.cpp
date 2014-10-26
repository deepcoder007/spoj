#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


long long int dp[70][10];
long long int ans[70];



int main()
{
	register int i,j,k;
	long long int tmp;
	for(i=0;i<10;i++)
		dp[1][i]=1;
	for(i=2;i<=64;i++)
	{
		for(j=0;j<10;j++)
		{
			tmp=0;  
			for(k=j;k<10;k++)
				tmp+=dp[i-1][k];
			dp[i][j]=tmp;
		}
	}
	for(i=1;i<=64;i++)
	{
		tmp=0;
		for(j=0;j<10;j++)
			tmp+=dp[i][j];
		ans[i]=tmp;
	}
	// now start the actual program
	int t,x,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		cout<<n<<" "<<ans[x]<<endl;
	}
	return 0;
}




