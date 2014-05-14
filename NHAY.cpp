#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
	int n;
	string pat;
	string str;
	bool oc=false;
	int index;
	while( scanf("%d",&n)!=EOF )
	{
		cin>>pat;
		cin>>str;
		index=0;
		oc=false;
		while( str.find(pat,index)!= string::npos )
		{
			index=str.find(pat,index);
			cout<<index<<endl;
			index++;
			oc=true;
		}
		if( oc==false)
			cout<<endl;
	}
	return 0;
}
		
