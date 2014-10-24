#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
// simple question of binary search

int gcd(int a,int b)
{
	int c;
	while( a!=0 )
	{
		c=a; a=b%a; b=c;
	}
	return b;
}

inline void test(int t)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int i,j,k;
	i=gcd(a,b);
	if( c%i== 0 )
	{
		printf("Case %d: Yes\n",t);
	}
	else printf("Case %d: No\n",t);

}

int main()
{
	int t;
	scanf("%d",&t);
	register int i;
	for(i=1;i<=t;i++)
		test(i);
	return 0;
}
