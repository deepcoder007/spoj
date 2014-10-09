#include<iostream>
#include<algorithm>
#include<functional>
#include<cstdio>
using namespace std;

int t,p,n,m;

int build[1001];   // the array to store the main buildings set

inline int getp(int x)   // get the representative element of the element x in set build
{
	while(x!=build[x])
	{ x=build[x]; }
	return x;
}

struct street
{
	int a;   //town a and b
	int b;
	int c;   // distance c;
	bool operator < (street s ) const
	{ return c  < s.c; }
	bool operator > ( street s ) const
	{  return c > s.c; }
};

street strt[300001];


// This is a simple MST problem
inline void test()
{
	scanf("%d",&p);
	scanf("%d",&n);
	scanf("%d",&m);
	register int i,j;
	int a,b,c;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		strt[i].a=a;
		strt[i].b=b;
		strt[i].c=c;
	}
	sort(strt,strt+m);
	for(i=1;i<=n;i++)
	{ build[i]=i; }
	long int sum=0;
	for(i=0;i<m;i++)
	{
		if( getp(strt[i].a)==getp(strt[i].b) )
			continue;
		else
		{ build[getp(strt[i].a)]=getp(strt[i].b); sum+=strt[i].c; }
	}
	cout<<sum*p<<endl;
}


int main()
{
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
