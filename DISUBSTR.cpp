#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<string>
using namespace std;


set<string> st[1010];   // array of set of strings

inline void test()
{
	int i,j,k;
	string in;
	cin>>in;
	set<string>::iterator it;
	int len=in.size();
	for(i=0;i<1010;i++)
		st[i].clear();  //initialize
	st[len].insert(in);   // len is the highest usable index
	for(i=len-1; i>0;i--)   // for all lengths
	{
		for(it=st[i+1].begin(); it!=st[i+1].end() ;it++)
		{
			st[i].insert( it->substr(0,i) );
			st[i].insert( it->substr(1,i) );
		}
	}
	int count=0;
	for(i=1;i<=len;i++)
		count+=st[i].size();
	cout<<count<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		test();
	return 0;
}

