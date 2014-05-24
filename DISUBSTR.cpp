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
	int len=in.size();
	for(i=0;i<1010;i++)
		st[i].clear();  //initialize
	st[len].insert(in);   // len is the highest usable index
	for(i=len-1; i>0;i--)   // for all lengths
	{
		for(j=0;j<=(len-i);j++)
		{
			st[i].insert(in.substr(j,i));
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

