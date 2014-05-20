// we need only the length of the sequence
#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
	int n;//  the number of numbers in the array
	cin>>n;
	int arr[n+1];   //stores the data
	int cnt[n+1];   //stores the count of the longest seq. ending at n
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	cnt[1]=1;       // base case 
	int max=0;
	for(i=2;i<=n;i++)   
	{
		max=1;
		for(j=1;j<i;j++)
		{
			if( arr[j]<arr[i]  && (cnt[j]+1)>max)
			{
				max=cnt[j]+1;
			}
		}
		cnt[i]=max;
	}
	// now output the max value of cnt[]
	max=1;
	for( i=1;i<=n;i++)
		if( cnt[i]>max)
			max=cnt[i];
	cout<<max<<endl;
	return 0;
}


