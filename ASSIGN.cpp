#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
// use bitwise to increase the speed

bool choice[25][25];   // choice matrix .. array are 0-ary for both students and the assignments
bool selected[25];    // to mark if the current assignment is selected or not
int n;
int tmp;
long long int f[1048576];



inline void test()
{
	register int i,j;
	scanf("%d",&n);
	memset(choice,false,sizeof(choice));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{ scanf("%d",&choice[i][j]); }
	}
	f[(1<<n)-1]=1;    // the case when all the students are selected
	int mask;

	for(mask= (1<<n)-2; mask>=0;  mask-- )
	{
		j=0;  // count the number of students in the current value of mask
		for(i=0;i<n;i++)
			if( (mask>>i)&1 )
				j++;

		f[mask]=0;
		for( i=0;i<n;i++ )
			if(choice[j][i] && (mask & ( 1<<i ))==0  )
				f[mask]+=f[mask | (1<<i) ];
	}
	printf("%lld\n",f[0]);

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
