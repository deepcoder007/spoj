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
//	cout<<"Entered the test case"<<endl;
	long long int n;
	cin>>n;
	n++;
	register int i;
	for(i=0;n>1;i++)
	{
		str[i]=(n%2==0)?5:6;
		n/=2;
	}
	while(i--)
	{
		if(str[i]==5) printf("5");
		else printf("6");
	}
	cout<<endl;
//	cout<<"Exiting the test case"<<endl;
}


int main()
{
	int n;
	scanf("%d\n",&n);
//	cin>>n;
	while(n--)
		test();
	return 0;
}
