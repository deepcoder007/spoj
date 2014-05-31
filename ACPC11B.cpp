#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;

int arr1[1010];
int arr2[1010];


inline int min(int a,int b)
{
	if( a<b ) return a;
	else return b;
}

inline void test()
{
	int n1,n2;
	int i,j;
	int tmp;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	        scanf("%d",&arr1[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	        scanf("%d",&arr2[i]);
	sort(arr1,arr1+n1);
	sort(arr2,arr2+n2);
	int mn=INT_MAX;
	i=0;j=0;
	while(i<n1 && j<n2)
	{
		if(arr1[i]>arr2[j])
		{
			mn=min(mn,arr1[i]-arr2[j]);
			j++;
		}
		else if(arr1[i]<arr2[j])
		{
			mn=min(mn,arr2[j]-arr1[i]);
			i++;
		}
		else {  mn=0; break; }
	}
	printf("%d\n",mn);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
