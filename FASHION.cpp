#include<cstdio>
using namespace std;

int men[11];
int women[11];

inline void test()
{
	int n;
	scanf("%d",&n);
	int m,w;
	register int i,j;
	int tmp;
	for(i=0;i<11;i++)
		men[i]=women[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		men[tmp]++;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		women[tmp]++;
	}
	int ans=0;
	i=10,j=10;
	while(1)
	{
		while(men[i]==0 && i>0) i--;
		while(women[j]==0 && j>0) j--;
		if( i!=0 && j!=0 )
		{
			ans+=i*j;
			men[i]--; women[j]--;
		}
		else break;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
		

