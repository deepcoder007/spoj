#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	string in;
	map<string,int> m;
	while(n--)
	{
		cin>>in;
		m.clear();
		m[in]=1;  //index of first element
		for(i=1;i<in.size();i++)
		{
			m[ in.substr(i) +in.substr(0,i)]=i+1;
		}
		cout<<m.begin()->second<<endl;
	}
	return 0;
}
