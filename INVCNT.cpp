#include<iostream>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
//use merge sort based approach
// all arrays are 0-ary
// after that convert the program to inversion count

int arr[10000000];
unsigned long long int mergesort(int* A,int n);

unsigned long long int  merge(int* A,int* B,int a,int b,int* C)   // C is the output array
{
	unsigned long long int invcount=0;
	int i=0,j=0,k=0;
	for(k=0;k<(a+b);k++)
	{
		if(i<a && j<b)
		{
		if(A[i]<=B[j])
		{ C[k]=A[i++]; }
		else { C[k]=B[j++]; invcount+=(a-i); }
		}
		else if( i==a )
			C[k]=B[j++];
		else
			C[k]=A[i++];
	}
	return invcount;
}


unsigned long long int mergesort(int* A,int n)   // merge sort an array having n numbers
{
	if(n==1)
		return 0;
	unsigned long long int  invcount=0;
	int mid=n/2;
	int* t1=new int[mid];
	int* t2=new int[n-mid];
	int i,j;
	for(i=0;i<mid;i++)
		t1[i]=A[i];
	for(;i<n;i++)
		t2[i-mid]=A[i];
	invcount+=mergesort(t1,mid);
	invcount+=mergesort(t2,n-mid);
	invcount+=merge(t1,t2,mid,n-mid,A);
	return invcount;
}

/*
int arr[100];
// a simple sorting program
int main()
{
	int n;
	cin>>n;
	cout<<"Enter n elements:"<<endl;
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	mergesort(arr,n);
	cout<<"The output array is:"<<endl;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

*/
	


inline void test()
{
	register int i;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%llu\n",mergesort(arr,n));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
