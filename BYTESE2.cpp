#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

inline int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

struct pt
{
	char mov;  // 1 = in , -1 = out
	int time; 
	bool operator < ( pt a ) const
	{
		return time < a.time;
	}
} pts[201];

int tmp1,tmp2;
int curr,mx;
int n,t;


inline void test()
{
	scanf("%d",&n);
	register int i,j;
	for(i=0;i<2*n;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		pts[i].mov=1;
		pts[i].time=tmp1;
		i++;
		pts[i].mov=-1;
		pts[i].time=tmp2;
	}
	sort(pts,pts+2*n);
	curr=mx=0;
	for(i=0;i<2*n;i++)
	{
		if(pts[i].mov==1)
		{
			curr++;
			mx=max(mx,curr);
		}
		else if( pts[i].mov==-1)
		{ curr--; }
	}
	printf("%d\n",mx);

}

int main()
{
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
