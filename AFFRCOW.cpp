#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int arr[100010];   // the array containing the position of cows
int n,c;
int t;


bool f(int x)   // returns true if this distance is possible
{
	int k=0;            // the index of position where last cow was palced
	int completed=1;             // the no. of cows placed
	register int i;
	for( i=1;i<n;i++)
	{
		if( (arr[i]-arr[k])>=x )  //i.e. sufficient dist
		{
			completed++;
			k=i;
		}
	}
	if( completed>=c) return true;
	else return false;
}



int ans()   //returns the answer for a test case
{
	int low=0,high=arr[n-1];
	int mid;
	while( low<high )
	{
		mid=(low+high)/2;
		if( f(mid)==true)    // search second half
			low=mid+1;
		else
			high=mid;
	}
	return low-1;
}

int main()
{
	scanf("%d",&t);
	register int i;
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for( i=0;i<n;i++)
			scanf("%d",arr+i);
		sort(arr,arr+n);   //sort the distances
		printf("%d\n",ans() );
	}
	return 0;
}
		
		
