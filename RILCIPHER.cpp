#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int tmp;
int n;

inline void test()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tmp);
		if(tmp<0 ) printf("%d ",tmp);
		else if(tmp==1) printf("-3 ");
		else if(tmp==2) printf("-2 ");
		else if(tmp==5) printf("-3 ");
		else printf("-4 ");
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
