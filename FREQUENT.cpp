#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int arr[100009];   // to store elements
int T[400000];    // The segment tree

int max(int a,int b)
{
	if( a >b ) return a;
	else return b;
}

void init(int n,int l,int r)
{
	if( l==r )
	{
		T[n]=1;
		return;
	}
	int mid = l + (r-l)/2;
	init(2*n,l,mid);
	init(2*n+1,mid+1,r);
	if( arr[mid]!=arr[mid+1] ) 
	{
		T[n]=max( T[2*n] , T[2*n+1] );
	}
	else
	{
		int i=0,j=0;
		for( i=0 ; (mid-i)>=l && arr[mid-i]==arr[mid] ; i++ );
		for( j=0 ; (mid+1+j)<=r && arr[mid+1+j]==arr[mid] ; j++ );
		T[n]= max( i+j , max( T[2*n] , T[2*n+1] ) );
	}
	return ;
}

int query(int n,int l,int r,int p,int q)  // query between p and q 
{
	if( l>=p && r<=q )
		return T[n];
	if( q<l || r<p ) return 0;
	if( l==r ) return T[n];
	int i=0,j=0;
	int mid=l +(r-l)/2;
	for( i=0 ; (mid-i)>=l && arr[mid-i]==arr[mid] ; i++ );
	for( j=0 ; (mid+1+j)<=r && arr[mid+1+j]==arr[mid] ; j++ );
	return max( i+j , max( query(2*n,l,mid,p,q ), query(2*n+1,mid+1,r,p,q)) );
}

int main()
{
	memset(T,0,sizeof(int)*400000);	
	int n,q;
	register int i;
	scanf("%d%d",&n,&q);
	for( i=0; i<n;i++)
		scanf("%d",&arr[i]);
	init(1,0,n-1);
	cout<<"DONE Init"<<endl;
//	for(i=0;i<10;i++)
//		cout<<T[i]<<endl;
	int l,r;
	for( i=0 ;i<q ; i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,0,n-1,l-1,r-1));
	}
	return 0;
}
	
		


	
	
		
	








