#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;

char str[410];
int l;
int i,j;

void test()
{
	scanf("%s",str);
	l=strlen(str);
	stack<char> stk;  // stack to hold the symbols
	for(i=0;i<l;i++)
	{
		if( str[i]=='(' )
			continue;
		else if( str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^' )
			stk.push(str[i]);
		else if( str[i]==')' )
		{
			printf("%c",stk.top() );
			stk.pop();
		}
		else
			printf("%c",str[i]);
	}
	printf("\n");
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
