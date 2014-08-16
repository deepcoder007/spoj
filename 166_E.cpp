#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
	int A=1,B=0;
	int A_new,B_new;
	int n=1;
	int i,j;
	scanf("%d",&i);
	for(n=1;n<=i;n++)
	{
		A_new=(B*3LL)%1000000007;
		B_new=(A+2LL*B)%1000000007;
		A=A_new;
		B=B_new;
	}
	printf("%d\n",A);
	return 0;
}


	

