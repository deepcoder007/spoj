#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

char str[100];

inline void test()
{
	cout<<"ENtered the test case"<<endl;
	long long int k;
	cin>>k;
	cout<<"Input is :"<<k<<endl;
	k--;
	int i=0;
	while(k!=0)
	{
		if(k%2==0)
		{ str[i++]='5'; }
		else str[i++]='6';
		k/=2;
	}
	i--;
	while(i>=0)
		cout<<str[i--];
	cout<<endl;
	cout<<"Exiting the test case"<<endl;
}


int main()
{
	int n;
//	scanf("%d\n",&n);
	cin>>n;
	while(n--)
		test();
	return 0;
}
