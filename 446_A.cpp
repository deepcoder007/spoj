#include<cstdio>
#include<iostream>
using namespace std;

int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

int arr[100009];

int main()
{
	int i_old,j_old,i,j,len_old,len,len_max;
	int n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	i=j=1;
	if(arr[2]>arr[1])
	{
		for(j=2 ; j<=n && arr[j]>arr[j-1];j++);
	}
	if(j==n && arr[n]>arr[n-1])
	{ cout<<n<<endl;return 0;} 
	j--;
	i_old=i;
	j_old=j;
	len_old=j-i+1;
	len_max=len_old;
	while(1)
	{










	
