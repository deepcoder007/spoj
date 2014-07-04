#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
using namespace std;


bool test()
{
	int N,M;  // n is the number of bugs, m is number of interactions
	cin>>N>>M;
	map<int,set<int> > m;
	int i,j,k;
	//initialize the set
	set<int> left;   // the set of elements that are not coloured
	for(i=1;i<=N;i++)
	{
		m[i]=set<int>();
		left.insert(i);
	}
	for(i=1;i<=M;i++)
	{
		cin>>j>>k;
		m[j].insert(k);
		m[k].insert(j);
	}
	int colour[N+1];  // 1 means white, 2 means black 
	int z;
	set<int> bag1;
	set<int> bag2;
	while(left.size() )  // there are uncoloured bugs
	{
		z=left.begin();   //take out the first bug
		colour[z]=1;     //by default
		// now traverse the whole family

		




}


int main()
{
	int n;
	cin>>n;
	int i;
	bool res;
	for(i=1;i<=n;i++)
	{
		res=test();
		printf("Scenario #%d:\n",i);
		if( res )
			printf("Suspicious bugs found!\n");
		else 
			printf("No suspicious bugs found!\n");
	}
	return 0;
}

