// This new method is based on preprocessing
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

int arr[50009];

inline long int max(long int a,long int b)
{
	if( a>b) return a;
	else return b;
}

class node_external
{
public:
	int* arr;
	int start_index;   //index of start element
	int end_index;     //index of last element
	long int sum_max;       //total sum to get O(1) time
	long int get_max(int a,int b)
	{
		if( a<=start_index && b>=end_index)
		{    return sum_max;  }
		else 
		{
			long int max_so_far=0;
			long int max_2=0;
			int i,j;
			for(i=start_index;i<=stop_index;i++)
			{
				if( i<a || i>b ) continue;
				max_2=max(0,max_2+arr[i-start_index]);
				max_so_far=max(max_so_far,max_2);
			}
			return max_so_far;
		}
	}
};

class node_internal
{
public:
	node_external* left;
	node_external* right;
	int start_index;
	int end_index;
	long int get_max(int a,int b)
	{
		if(left->end_index<




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

