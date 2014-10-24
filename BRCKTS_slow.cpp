#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

string str;
int len;
int q;
int tmp;

// checks the str -> returns true if bracket is balanced
bool checkme()
{
	int cnt=0;
	register int i;
	for(i=0;i<len;i++)
	{
		if( str[i]=='(')
			cnt++;
		else
		{
			cnt--;
			if( cnt <0 ) return false;
		}
	}
	if(cnt==0)
	return true;
	else return false;
}


inline void test()
{
	cin>>len;
	cin>>str;
	cin>>q;
	while(q--)
	{
		cin>>tmp;
		if(tmp==0)
		{
			if(checkme()) { printf("YES\n"); }
			else { printf("NO\n"); }
		}
		else
		{
			if( str[tmp-1]==')' )
				str[tmp-1]='(';
			else
				str[tmp-1]=')';
		}
	}
}

int main()
{
	register int i;
	for(i=1;i<=10;i++)
	{
		printf("Test %d:\n",i);
		test();
	}
	return 0;
}
