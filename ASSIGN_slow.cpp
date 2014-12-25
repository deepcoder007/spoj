#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

bool choice[25][25];   // choice matrix .. array are 0-ary for both students and the assignments
bool selected[25];    // to mark if the current assignment is selected or not
int n;
int tmp;


long long int getcount(int a)     // for the a the row in the matrix
{
	long long int sum=0;
	register int i;
	if(a==(n-1))   // if this is the last row
	{
		for(i=0;i<n;i++) 
		{
			if(!selected[i] && choice[n-1][i] ) 
				sum++;
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(!selected[i] && choice[a][i])   
			{
				selected[i]=true;
				sum+=getcount(a+1);
				selected[i]=false;
			}
		}
	}
	return sum;
}

inline void test()
{
	register int i,j;
	scanf("%d",&n);
	memset(choice,false,sizeof(choice));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&choice[i][j]);
		}
	}
	memset(selected,false,sizeof(selected));
	printf("%lld\n",getcount(0));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
