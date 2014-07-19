#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
	int i,j;
	long int k;
	string str;
	char c;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>i;
		cin>>str;
		j=0;k=0;
		for(i=0;i<str.size();i++)
		{
			if(str[i]=='1')
			{
				j++;
				k+=j;
			}
		}
		cout<<k<<endl;
	}
	return 0;
}
