#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long int T[100009];  // A one ary array
int n,c;


inline void add(int x,int v)   // add v to the index x
{
	while(x<=n)
	{
		T[x]+=v;
		x+=(-x&x);
	}
}

inline long int get(int x)
{
	long int sum=0;
	while(x>0)
	{
		sum+=T[x];
		x-=(-x&x);
	}
	return sum;
}

	

void test()
{
//	cin>>n>>c;
	scanf("%d%d",&n,&c);
	register int i,j,k;
	int p,q,v;
	long int sum;
	int choice;   //either 0 or 1
	for(i=1;i<=n;i++)
		T[i]=0;
	for(i=0;i<c;i++)	
	{
//		cin>>choice>>p>>q;
		scanf("%d%d%d",&choice,&p,&q);
		if( choice== 0 )   // add another input used for updation of the ring
		{
//			cin>>v;   	// the value that  needs to be added to all the elements
			scanf("%d",&v);
			for(j=p;j<=q;j++)
			{
				add(j,v);
			}
		}
		else
		{
			sum=get(q)-get(p-1);
//			cout<<sum<<endl;
			printf("%ld\n",sum);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
