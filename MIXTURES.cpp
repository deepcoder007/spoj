#include<cstdio>
#include<iomanip>
#include<climits>
#include<iostream>
using namespace std;

int m[101];   // holds the colour of mixtures

inline int min(int a,int b)
{
	if( a>b) return b;
	else return a;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	int* arr1[n+1]; // holds the value
	int* arr2[n+1]; //holds the colour
	register int i,j,k;
	for(i=0;i<=n;i++)
	{
		arr1[i]=new int[n+1];
		arr2[i]=new int[n+1];
		for(j=0;j<=n;j++)
		{
			arr1[i][j]=INT_MAX;  //the max cost , we have to relax
			arr2[i][j]=-1;   //an invalid colour
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr2[i][i]);
		arr1[i][i]=0;   //cost
	}
	int col=-1;
	int m=INT_MAX;
	int t1,t2;     //temporary variables
	for(j=1;j<n;j++)   // the difference between the left right
	{
		for(i=1;i<=(n-j);i++)  // for all combinations with this diff.
		{
			m=INT_MAX;
			col=-1;        //split point
			for(k=0;k<j;k++) //split within the difference
			{
				t1=arr2[i][i+k]*arr2[i+k+1][i+j]+arr1[i][i+k]+arr1[i+k+1][i+j];
				if(min(t1,m)==t1) //i.e. change needed
				{
					m=t1;
					arr1[i][i+j]=t1;
					arr2[i][i+j]=(arr2[i][i+k]+arr2[i+k+1][i+j])%100;
				}
			}
		}
	}
	cout<<arr1[1][n]<<endl;
	}
	return 0;
}










