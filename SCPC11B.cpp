#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int stations[1425];
int max(int a,int b)
{
	if( a> b ) return a;
	else return b;
}
int n;  // number of stations


int main()
{
	register int i;
	int diff;
	while(1)
	{
		diff=0;
		scanf("%d",&n);
		if( n== 0 ) return 0;
		for(i=0;i<n;i++)
			scanf("%d",&stations[i]);
		stations[i]=1422;
		n++;
		sort(stations,stations+n);
		for(i=1;i<=n;i++)
		{
			diff=max(diff,stations[i]-stations[i-1]);
		}
		if(diff>200)
			printf("IMPOSSIBLE\n");
		else
			printf("POSSIBLE\n");
	}
	return 0;
}



