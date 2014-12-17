#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

bool isprime[10000];
int  factor[10000];   // count the number of prime factors of this number
vector<int> v;      // vector of lucky numbers


void init()
{
	memset(isprime,true,sizeof(isprime));
	memset(factor,0,sizeof(factor));
	register int i,j;

	for( i=2;i<9000;i++)
	{
		if(isprime[i])
		{
			for(j=2*i; j<=9000;j+=i)
			{
				factor[j]++;
				isprime[j]=false;
			}
		}
	}
	v.push_back(0);
	for(i=30;i<=9000;i++)
	{
		if(factor[i]>=3)
			v.push_back(i);
	}
}




int main()
{
	init();
//	int i;
	//////////////


	/////////////
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",v[n]);
	}
	return 0;
}

