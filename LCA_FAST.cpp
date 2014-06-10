#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;

int parent[1009];
vector<int> par1,par2;

inline void test(int &t)  //input is the particular test case
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<=n;i++)
		parent[i]=-1;   // means own parent
	int tmp1,tmp2;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tmp1);
		for(j=0;j<tmp1;j++)
		{
			scanf("%d",&tmp2);
			parent[tmp2]=i;
		}
	}
	//the leftout node with -1 is the root of tree
	//set<int> par2;
	// make path to parent for all nodes
	map<int,vector<int> > p2p;   //path to parent
	for(i=1;i<=n;i++)
	{
		p2p[i]=vector<int>();
		j=i;
		do
		{
			p2p[i].push_back(j);
			j=parent[j];
		}while(j!=-1);
	}
	int q;
	cin>>q; // no. of queries
	printf("Case %d:\n",t);
	int u,v;
	for(i=1;i<=q;i++)
	{
		cin>>u>>v;
		j=p2p[u].size()-1;
		k=p2p[v].size()-1;
		for(; j>=0 && k>=0 && p2p[u][j]==p2p[v][k]; j--,k--);
		cout<<p2p[u][j+1]<<endl;
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for( i=1;i<=t;i++)
		test(i);
	return 0;
}
