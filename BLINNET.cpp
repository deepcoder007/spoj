#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;


struct edge
{
	int src;
	int dst;
	int weight;
	bool operator < (edge e) const
	{ return weight < e.weight; }
};
	char stmp[1000];    // the temporary string
	bool covered[10001];   // store if the city is covered
	int n;   // number of cities
	int  t1,t3;
	long long int t2;

inline void test()
{
	long long int cost=0;  // the answer
	scanf("%d",&n);
	int covered_count=0;
	vector<edge> g(1000000);
	int n2;
	register int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s",stmp);
		scanf("%d",&n2);  // the number of edges to this vertex
		while(n2--)
		{
			scanf("%d%lld",&t1,&t2);
			if(t1<i) continue;
			g.push_back((edge){i,t1,t2});
		}
	}
	sort(g.begin(),g.end());
	vector<edge>::iterator it;
	memset(covered,false,sizeof(covered));
	covered[g.begin()->src]=true;
	covered_count=1; 
	while(covered_count!=n) // the total number of nodes
	{
		for(it=g.begin();it!=g.end();it++)
		{
			if(covered[it->src] && covered[it->dst] )
			{ g.erase(it);break; }
		}
		for(it=g.begin();it!=g.end();it++)
		{
			if((covered[it->src] && !covered[it->dst]) || (!covered[it->src] && covered[it->dst]))
			{
				covered[it->src]=covered[it->dst]=true;
				cost+=it->weight;
				covered_count++;
				break;
			}
		}
	}
	printf("%lld\n",cost);

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
