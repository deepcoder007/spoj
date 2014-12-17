#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace  std;

long long int k;
int e,t,n;   // expected 1=male, -1 =female



int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		n=0;
		while(k!=0)
		{
			if(k%2==0) n++;
			k=(k>>1);
		}
		if(n%2==1) printf("Female\n");
		else printf("Male\n");
	}
}
