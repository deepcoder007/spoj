#include<iostream>
using namespace std;


int arr[50001];
int n;
int m;

int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

int max_s(int* arr,int i,int j)  //i,j are inclusive
{
	if(i==j) return arr[i];
	int left=max_s(arr,i,(i+j)/2);
	int right=max_s(arr,(i+j)/2 +1,j);
	int l1=0,l2=0;  //l2 stores the max. l1 stores the current sum
	int k;
	for(k=(i+j)/2;k>0;k--)
	{
		l1+=arr[k];
		l2=max(l1,l2);
	}
	int l_left=l2;
	l1=0;l2=0;
	for(k=(i+j)/2 +1;k<=j;k++)
	{
		l1+=arr[k];
		l2=max(l1,l2);
	}
	int r_right=l2;
	return max(max(left,right),l_left+r_right);
}

int main()
{
	cin>>n;
	register int i,j;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	cin>>m;
	int a,b,c;
	while(m--)
	{
		cin>>a>>b>>c;
		if(a==0)  {  arr[b]=c; }
		else {  cout<<max_s(arr,b,c)<<endl; }
	}
	return 0;
}
	
	
