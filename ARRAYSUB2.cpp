#include<iostream>
#include<vector>
using namespace std;

int m(int &a,int &b)
{
	if(a>b) return a;
	else return b;
}

int arr[1000009];
int out[1000009];


int main()
{
int max;
	max=0;
	int n,k;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	for(i=0;i<k;i++)
		max=m(max,arr[i]);
	for(i=k-1;i<n;i++)
	{
		max=m(max,arr[i]);
		out[i-k+1]=max;
		if( arr[i-k+1]==max )   // i.e. the element to be delted is max
		{
			//find the new max
			max=0;
			for(j=i-k;j<i;j++)
				max=m(max,arr[j]);
		}
	}
	for(i=0;i<(n-k);i++)
	{
		cout<<out[i]<<' ';
	}
	cout<<out[n-k]<<endl;
	return 0;
}
		
		




