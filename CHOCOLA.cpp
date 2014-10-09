#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;


class dats
{
public:
	int key;   // the cost
	char val;   //if horizontal or vertical
	bool operator < (dats tmp ) const
	{
		return key < tmp.key;
	}
	bool operator > (dats tmp) const
	{
		return key > tmp.key;
	}
};




void test()
{
	int m,n;
	int h=0,v=0;    //counts the number of horizontal and vertical cuts
	vector<int> vh,vv;  // stores the cost of cuts
	register int i,j;
	scanf("%d %d",&m,&n);
	int tmp;
	dats maps[m+n-2];
	int c=0;
	
	for(i=1;i<m;i++)
	{
		scanf("%d",&tmp);
		vh.push_back(tmp);
		maps[c].key=tmp;
		maps[c++].val='h';
	}
	for(i=1;i<n;i++)
	{
		scanf("%d",&tmp);
		vv.push_back(tmp);
		maps[c].key=tmp;
		maps[c++].val='v';
	}
//	sort(vv.begin(),vv.end(),greater<int>());
//	sort(vh.begin(),vh.end(),greater<int>());
	sort(maps,maps+m+n-2,greater<dats>());
	int cost=0;
	for(i=0;i<(m+n-2);i++)
	{
		if( maps[i].val=='h' )
		{
			cost+=(v+1)*maps[i].key; 
			h++;
		}
		else
		{
			cost+=(h+1)*maps[i].key;
			v++;
		}
	}
	printf("%d\n",cost);
	return;
}
		
			
			
		
int main()
{
	int t;
	scanf("%d",&t);	
	while(t--)
		test();	
	return 0;
}
