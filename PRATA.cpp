#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;



inline int min(int a,int b)
{
	if( a< b) return a;
	else return b;
}
inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

int rank[55];     // the rank as given input
int num_comp[55];     // the number of parathas made till now
int next_stop[55];   // the stop time of respective chef for the job [processed]


inline void test()
{
	register int tmp1,tmp2;
	int P,N;
	register int i,j;
	scanf("%d%d",&P,&N);
	for(i=0;i<N;i++)
	{ scanf("%d",&rank[i]); }
	memset(num_comp,0,sizeof(num_comp));
	memset(next_stop,0,sizeof(next_stop));
	for(i=0;i<P;i++)   // for all the parathas
	{
		tmp1=0;
		tmp2=next_stop[0]+(num_comp[0]+1)*rank[0];  // tentative finish time
		for(j=1;j<N;j++)   // for queue of all chefs
		{
			if( tmp2 > ( next_stop[j]+(num_comp[j]+1)*rank[j] ) )
			{
				tmp1=j;
				tmp2=next_stop[j]+(num_comp[j]+1)*rank[j];
			}
		}
		num_comp[tmp1]++;
		next_stop[tmp1]+= (num_comp[tmp1]*rank[tmp1]);
	}
	tmp1=0;
	for(i=0;i<N;i++)
	{ tmp1=max(tmp1,next_stop[i]); }
	printf("%d\n",tmp1);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
