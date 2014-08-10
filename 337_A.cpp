#include<iostream>
#include<climits>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int min(int a,int b)
{
	if( a<b )
	{ return a; }
	else
	{ return b; }
}


int arr[60];

int main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	for(i=0;i<m;i++)
		cin>>arr[i];
	sort(arr,arr+m);
	int mi=INT_MAX;
	for(i=0;i<(m-n+1);i++)
	{
		mi=min(mi,arr[i+n-1]-arr[i]);
	}
	cout<<mi<<endl;
	return 0;
}


