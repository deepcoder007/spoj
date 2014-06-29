#include<cstdio>
#include<iostream>
using namespace std;

int arr[300010];

inline long int max(long int a,long int b)
{
	if( a>b) return a;
	else return b;
}

int main()
{
	long int M;
	long int mx=0;
	long int curr=0;
	int N;
	scanf("%d %ld",&N,&M);
	int i,j;
	for(i=0;i<N;i++)
		scanf("%d",arr+i);
	i=0;j=0;  //contains inclusive
	bool flag=false;
	for(j=0;j<N;j++)
	{
		curr+=arr[j];
		if( curr<= M) mx=max(mx,curr);
		else 
		{
			while( curr> M)
			{
				curr-=arr[i];
				i++;
			}
			mx=max(mx,curr);
		}
	}
	printf("%ld",mx);
	return 0;
}





