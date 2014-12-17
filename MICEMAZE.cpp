// adjacency list method;
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
using namespace std;

int n,e,t,m;
bool visited[110];   // to mark if the cell is already inside
int dist[110];         // dist of the node from the origin... in case of not visited , the distance in infinite

struct edge
{
	int from;
	int to;
	int time; // time in seconds
	bool operator < ( edge ed ) const   // assumed that from is visited and to is not visited
	{ return (dist[from]+time) < (dist[ed.from]+ed.time); }
	bool operator > (edge ed ) const
	{ return ( dist[from]+time) > (dist[ed.from]+ed.time); }
};

struct edg   // for storing int the vector
{
	int v;
	int time;
};

vector<vector<edg> > G(105);   // to store the graph
//set<edge> st;    // the set of edges we will be working on
vector<edge> st;
set<edge>::iterator it;

int main()
{
	register int i;
	scanf("%d%d%d%d",&n,&e,&t,&m);
	int a,b,c;
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		G[b].push_back((edg){a,c});
	}
	memset(visited,0,sizeof(visited));
	memset(dist,-1,sizeof(dist));
	visited[e]=1; // the source
	dist[e]=0;   // the source
	vector<edg>::iterator it;
	for(it=G[e].begin();it!=G[e].end(); it++)
		st.push_back((edge){e,it->v,it->time});
//	cout<<"SOURCE DISCOVERED AT: "<<e<<endl;
	int f=1; // flag to detect change
	edge etmp,vtmp;
	vector<edge>::iterator sit;
	while(!st.empty())
	{
		f=0;
		sort(st.begin(), st.end());
		etmp=*st.begin();
//		cout<<"EDGE ADDED   --- FROM : "<<etmp.from<<"  TO : "<<etmp.to<<endl;
		visited[etmp.to]=true;
		dist[etmp.to]=dist[etmp.from]+etmp.time;

		// now remove all the edges to etmp.to in the list st
		for(sit=st.begin();sit!=st.end();)
		{
			if(sit->to==etmp.to) // remove this
			{
				st.erase(sit);
				continue;
			}
			sit++;
		}
		// now add all the edges from etmp.to to the st
		for(it=G[etmp.to].begin();it!=G[etmp.to].end();it++)
			if(visited[it->v]==false)
				st.push_back((edge){etmp.to, it->v, it->time });
//		cout<<"ITERATION END: "<<endl;
//	cout<<"THE VISITING TIMES ARE: "<<endl;
//	for(i=1;i<=n;i++)
//		cout<<dist[i]<<"\n";
	}
//	cout<<"THE VISITING TIMES ARE: "<<endl;
//	for(i=1;i<=n;i++)
//		cout<<dist[i]<<"\t"<<endl;
	int count=0;
	for(i=1;i<=n;i++)
		if(dist[i]<=t  && dist[i]!=-1)
			count++;
	printf("%d\n",count);

	return 0;
}
