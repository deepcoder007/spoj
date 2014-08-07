#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int arr[100009];

inline void test()
{
	int i,j;
	int a,b;
	scanf("%d%d",&a,&b);  // a=no. of station, b=max number of humans 
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	i=j=0;   // the left and right index
	while(arr[i]>b && i<a)
		i++;
	j=i;
	if(i==a)   // i.e. all elements are bigger 
	{
		printf("%d %d\n",0,0);
		return ;
	}
	int sum=arr[i];   // the sum of elements currently under consider.
	int count=1;   // the count of elements currently under consideration
	int sum_max=sum;
	int count_max=0;
	while(1)
	{
		if(sum<=b)
		{
			if(count>count_max || (count==count_max && sum_max<sum) )
			{ sum_max=sum; count_max=count; }
			j++;
			if(j==a) break;  // the process completed
			sum+=arr[j];
			count++;
		}
		else 
		{
			sum-=arr[i];
			count--;
			i++;
		}
	}
	printf("%d %d\n",sum_max,count_max);
			
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
