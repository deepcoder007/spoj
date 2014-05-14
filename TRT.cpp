#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

inline int max(int a,int b)
{
	if( a>=b) return a;
	else return b;
}



int main()
{

	int n;
	cin>>n;
	register int i,j,k;
	int v[n+1];
	for( i=1;i<=n;i++)  //input the weights
		cin>>v[i];
	int* arr[n+1];
	for( i=1;i<=n;i++)
		arr[i]=new int[n+1];
	for( i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			arr[i][j]=0;
	for(i=1;i<=n;i++)   //unit diagonal elements
		arr[i][i]=v[i];
	for(i=2;i<=n;i++)
	{
		for(j=i-1;j>0;j--)
		{
			arr[i][j]=max( arr[i-1][j]+ (i-j+1)*v[i] ,
					arr[i][j+1] + (i-j+1)*v[j] );
		}
	}
	cout<<arr[n][1]<<endl;
	cout<<"THE MATRIX :"<<endl;
	for( i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<setw(4)<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}

