#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;

inline int min(int a,int b)
{
	if( a<b) return a;
	else return b;
}

int main()
{
	int m1;
	int N,M;
	cin>>N>>M;
	int arr[N+1][M+1];  // 1-ary array
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			cin>>arr[i][j];
	for(i=N-1;i>0;i--)  
	{
		arr[i][1]+=min(arr[i+1][2],arr[i+1][1]);
		for(j=2;j<M;j++)
		{
			arr[i][j]+=min(min(arr[i+1][j+1],arr[i+1][j-1]),arr[i+1][j]);
		}
		arr[i][M]+=min(arr[i+1][M-1],arr[i+1][M]);
	}
	//find min of arr[1];
	m1=arr[1][1];
	for( i=2;i<=M;i++)
	{
		m1=min(m1,arr[1][i]);
	}
	cout<<m1<<endl;
	return 0;
}



		
