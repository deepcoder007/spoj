#include<cstdio>
using namespace std;

int arr[50009];

inline long  int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

// get max summation between the index x and y in array arr
long int get_max(int* arr,int x,int y)
{
	long int max_so_far=0;
	long int max_2=0;
	int i,j;
	for(i=x;i<=y;i++)
	{
		max_2=max(0,max_2+arr[i]);
		max_so_far=max(max_so_far,max_2);
	}
	return max_so_far;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		printf("%ld\n",get_max(arr,i,j));
	}
	return 0;
}

