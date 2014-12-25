#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int n;
int tmp;
int tmp2;



int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tmp);
		if(tmp%2==1)
			printf("%d\n",tmp);
		else
		{
			tmp2=0;
			while(tmp)  // i.e. tmp>0
			{
				tmp2=(tmp2<<1)+(tmp%2);
				tmp=(tmp>>1);
			}
			printf("%d\n",tmp2);
		}
	}
	return 0;

}






