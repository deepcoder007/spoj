#include<iostream>
#include<cstdio>
using namespace std;

int arr[20010];


int main()
{
	arr[0]=0;
	arr[1]=0;
	int i;
	int p=2;
	for(i=2;i<=20000;i++)
	{
		if( i==p )  //i.e. a power of 2
		{
			arr[i]=arr[i-1]+1;
			p*=2;
		}
		else arr[i]=arr[i-1];
	}
	int n;
	while(true)
	{
		cin>>n;
		if(n==0) break;
		else cout<<arr[n]<<endl;
	}
	return 0;
}
	
	
