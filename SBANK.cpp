#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;


int main()
{
	int t;
		char str[40];
		int count;
		char dummy;
	for( scanf("%d",&t); t; t--)
	{
		map<string, int> table;
		map<string, int>::iterator it;
		for( scanf("%d\n",&count);count;count--)
		{
			gets(str);
			table[(string)str]++;
		}
		for(it=table.begin(); it!=table.end();it++)
		{
			printf("%s %d\n",it->first.c_str(), it->second);
		}
		printf("\n");
	}
}

