#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	set<int> s;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		s.insert(arr[i]);
	}
	sort(arr,arr+n);
	int count=0;
	for(i=0;i<n;i++)
	{
		if( s.find(arr[i]+k)!=s.end() )
			count++;
	}
	cout<<count<<endl;
	return 0;
}
