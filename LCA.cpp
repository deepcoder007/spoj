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
	
	int u,v;
	int q;
	scanf("%d",&q);
	printf("Case %d:\n",t);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		j=u;
		par1.clear(); par2.clear();
		do
		{
			par1.push_back(j);
			j=parent[j];
		}while(j!=-1);  //i.e. the root node
		j=v;
		do
		{
			par2.push_back(j);
			j=parent[j];
		}while(j!=-1);
		j=par1.size()-1;
		k=par2.size()-1;
		for( ; j>=0 && k>=0 && par1[j]==par2[k]; j--,k-- );
		cout<<par1[j+1]<<endl;
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
