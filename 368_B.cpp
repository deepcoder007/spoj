#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int arr[100009];
int ans[100009];
int n,m;
set<int> s;


int main()
{
	cin>>n>>m;
	int i,j,k;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	ans[n]=1;
	s.insert(arr[n]);
	for(i=n-1;i>=1;i--)
	{
		if( s.find(arr[i])==s.end() )
		{ ans[i]=ans[i+1]+1; }
		else
		{ ans[i]=ans[i+1];   }
		s.insert(arr[i]);
	}
	for(i=0;i<m;i++)
	{
		cin>>j;
		cout<<ans[j]<<endl;
	}
	return 0;
}

	
