#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int arr[160000];

int main()
{
	int n,k;
	cin>>n>>k;
	int i,j;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	int i_min=1;
	int sum_min=0;
	int sum=0;
	for(i=1;i<=k;i++)
	{ sum+=arr[i]; }
	sum_min=sum;
	for(i=2;i<=(n-k+1);i++)
	{
		sum-=arr[i-1];
		sum+=arr[i+k-1];
		if(sum<sum_min)
		{
			sum_min=sum;
			i_min=i;
		}
	}
	cout<<i_min<<endl;
	return 0;
}












	
