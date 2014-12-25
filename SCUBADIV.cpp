#include<iostream>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;


int dp[1005][401][401];  // the array are 1-ary
int w[1005];
int ox[1005];
int nit[1005];
int t,a,n;

inline int min(int a,int b)
{
	if( a< b) return a;
	else return b;
}

inline int max(int a,int b)
{
	if( a>b) return a;
	else return b;
}

inline void test()
{
//	cout<<"Entering the test case:"<<endl;
	register int i,j,k;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&t,&a);
	scanf("%d",&n);   /// number of cylinders
	for(i=0;i<n;i++)
		scanf("%d%d%d",&ox[i],&nit[i],&w[i]);
	// now start the dp
	for(i=0;i<n;i++)
		dp[i][0][0]=0;   // this position is always possible
	dp[0][ox[0]][nit[0]]=w[0];   // the base case
//	cout<<"w[0]"<<w[0]<<endl;
	for(i=1;i<n;i++)
		for(j=1;j<=400;j++)
			for(k=1;k<=400;k++)
			{
				if(dp[i-1][j][k]==-1)   // if using (i-1) items the current position is not possible
				{
				  if( (j-ox[i])>=0 && (k-nit[i])>=0 )
				  {
					if(dp[i-1][j-ox[i]][k-nit[i]]==-1)   // if the reduced position is also not possible
					{
						dp[i][j][k]=-1;
					}
					else
					{
						dp[i][j][k]=dp[i-1][j-ox[i]][k-nit[i]]+w[i];
					}
				  }
				  else
				  {
					  dp[i][j][k]=-1;
				  }
				}
				else   // if using (i-1) items the current position is possible
				{
				  if( (j-ox[i])>=0 && (k-nit[i])>=0 )
				  {
					if(dp[i-1][j-ox[i]][k-nit[i]]==-1)
					{
						dp[i][j][k]=dp[i-1][j][k];
					}
					else
					{
						dp[i][j][k]=min(dp[i-1][j-ox[i]][k-nit[i]]+w[i],dp[i-1][j][k]);
					}
				  }
				  else
				  {
					  dp[i][j][k]=dp[i-1][j][k];
				  }
				}
			}
			/*
	cout<<"DEBUG info"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<endl<<endl<<endl<<endl;
		cout<<"Item : "<<i<<endl;
		for(j=0;j<=29;j++)
		{
			for(k=0;k<=89;k++)
			{
				cout<<dp[i][j][k]<<"  ";
			}
			cout<<endl;
		}
	}
	*/
	int m=INT_MAX; // store the minima
	for(i=t;i<=400;i++)
	{
		for(j=a;j<=400;j++)
		{
			if(dp[n-1][i][j]!=-1)
				m=min(m,dp[n-1][i][j]);
		}
	}
	printf("%d\n",m);

//	cout<<"Exit test"<<endl;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}


