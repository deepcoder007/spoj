#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

int C[100000];
int P[100000];

inline void test(int n)
{
	register int i;
	for(i=0;i<n;i++)
		scanf("%d",&C[i]);
	for(i=0;i<n;i++)
		scanf("%d",&P[i]);
	sort(C,C+n);
	sort(P,P+n,greater<int>());
	long int sum=0;
	for(i=0;i<n;i++)
		sum+=C[i]*P[i];
	printf("%ld\n",sum);
}

int main()
{
	int t;
	while(1)
	{
		scanf("%d",&t);
		if(t==0 ) break;
		test(t);
	}
	return 0;
}
