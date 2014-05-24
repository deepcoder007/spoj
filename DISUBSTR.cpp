#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
using namespace std;

struct node;

struct node
{
	map<char,node> chars;
};


//Build a suffix array
class Suffix
{
private:
	map<char,node> head;   // the super node
	void addS(string in,node& nd) // add string to node nd
	{
		if(in.size()==0) return ;
		register int i;
		node* chr=&nd;
		for(i=0;i<in.size();i++)
		{
		     chr=&(chr->chars[in[i]]);
		}
	}
	int count;
public:
	void add(string in)
	{
		addS(in.substr(1) ,head[in[0]]);
	}
	void ite(map<char,node> & mp) // iterate this map
	{
		map<char,node>::iterator it;
		for(it=mp.begin() ;it!=mp.end() ;it++)
		{
			count++;
			ite(it->second.chars);
		}
	}
	void print()
	{
		count=0;
		ite(head);
		cout<<count<<endl;
	}
};


inline void test()
{
	string str;
	Suffix s;
	cin>>str;
	int i;
	for(i=0;i<str.size();i++)
		s.add(str.substr(i));
	s.print();
}


int main()
{
	int t;
	cin>>t;
	while(t--)
		test();
	return 0;
}

