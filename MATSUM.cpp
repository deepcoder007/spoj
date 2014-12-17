#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cstring>
using namespace std;
// BIT is 1 ary

int raw[1100][1100];   // the original data
int cum[1100][1100];   //  the tree data


class bit2d
{
	int n;                 // the size of the matrix
public:
	void reset(int k)
	{
		memset(raw,0,sizeof(raw));
		memset(cum,0,sizeof(cum));
		n=k;
	}
	void add(int x,int y,int v)
	{
		raw[x][y]+=v;
		int i,j;
		for(i=x;i<=n;i+=(i&-i))
			for(j=y;j<=n;j+=(j&-j))
				cum[i][j]+=v;
	}
	int read(int x,int y)
	{
		int i,j;
		int sum=0;
		for(i=x;i>0;i-=(i&-i))
			for(j=y;j>0;j-=(j&-j))
				sum+=cum[i][j];
		return sum;
	}
	void set(int x,int y,int v)
	{
		add(x,y,v-raw[x][y]);
		raw[x][y]=v;
	}
};


int main()
{
	int t1,t2,t3,t4;
	bit2d tree;
	int t,n;
	char str[6];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree.reset(n);
		while(1) 
		{
			scanf("%s",str);
			if(strcmp(str,"END")==0)
				break;
			else if(strcmp(str,"SET")==0)
			{
				scanf("%d%d%d",&t1,&t2,&t3);
				tree.set(t1+1,t2+1,t3);
			}
			else if(strcmp(str,"SUM")==0)
			{
				scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
				t1++;t2++;t3++;t4++;
				int sum;
				sum=tree.read(t3,t4);
//				cout<<" t3, t4  : "<<tree.read(t3,t4)<<endl;
				sum-=tree.read(t1-1,t4);
//				cout<<" t1, t4  : "<<tree.read(t1-1,t4)<<endl;
				sum-=tree.read(t3,t2-1);
//				cout<<" t3, t2  : "<<tree.read(t3,t2-1)<<endl;
				sum+=tree.read(t1-1,t2-1);
//				cout<<" t1, t2  : "<<tree.read(t1-1,t2-1)<<endl;
				printf("%d\n",sum);
			}
		}
	}
	return 0;
}


