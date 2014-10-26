#include<iostream>
#include<cstdio>
#include<functional>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int arr[50][50];
int breaks[20];

inline void test()
{
//	cout<<"Entering the test case"<<endl;
	int n,k;
	int tmp;
	register int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<k;i++)
	{ scanf("%d",&breaks[i]); }
	sort(breaks,breaks+k);
	/*
	if( breaks[0]!=1 )
	{
		cout<<"no 1 found... exititng"<<endl;
		cout<<0<<endl;
		return ;
	}
	*/
	// the base conditions
	for(i=0;i<=2*n;i++)
		arr[1][i]=0;
	arr[1][1]=1;
	if(breaks[0]!=1) arr[1][0]=1;
//	cout<<"base condition initilized"<<endl;
	int b=0;     // to point to the current break in the list
	for(i=2;i<=2*n;i++)
	{
		if( breaks[b]!= i )  // if the current element is not at the break
		{
//			cout<<"No. break at = "<<i<<endl;
			arr[i][0]=arr[i-1][1];
//			cout<<"curren ans =  "<<arr[i][0]<<endl;
			for(j=1;j<n;j++)
			{
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j+1];
			}
			arr[i][n]=arr[i-1][j-1];
			arr[i][n+1]=0;
		}
else
		{
//			cout<<"Break found at i = "<<i<<endl;
			b++;
			arr[i][0]=0;
//			cout<<"curren ans =  "<<arr[i][0]<<endl;
			for(j=1;j<=k;j++)
			{
				arr[i][j]=arr[i-1][j-1];
			}
		}
	}
	cout<<arr[2*n][0]<<endl;
//	cout<<"Printing the table"<<endl;
/*
	for(i=1;i<=2*n;i++)
	{
		for(j=0;j<=2*n;j++)
		{	cout<<arr[i][j]<<" ";	}
		cout<<endl;
	}
	*/
//	cout<<"Exiting the test case "<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
