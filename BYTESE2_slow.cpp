#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

inline int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int t,n;
//int count;
int mx;
char arr[10000001];
int tmp1,tmp2;

inline void test()
{
	memset(arr,0,sizeof(arr));
	scanf("%d",&n);
	register int i=n;
	while(i--)
	{
		scanf("%d%d",&tmp1,&tmp2);
		arr[tmp1]=1;
		arr[tmp2]=-1;
	}
	int count=0;
	mx=0;
	for(i=0;i<=10000000;i++)
	{
		if(arr[i]==1)
		{
			count++;
			mx=max(mx,count);
		}
		else if(arr[i]==-1)
			count--;
	}
	printf("%d\n",mx);

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
