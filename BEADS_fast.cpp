#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,j,k,l;
	int mi;
	string in;
	while(n--)
	{
		cin>>in;
		mi=0;
		for(i=1;i<in.size();i++)
		{
			if(in[mi]>in[i])
			{
				mi=i;
			}
			else if(in[mi]==in[i])
			{
				if( string(in.substr(i)+in.substr(0,i)) < string(in.substr(mi)+in.substr(0,mi)) )
				{
					mi=i;
				}
			}
		}
		cout<<mi+1<<endl;
	}
	return 0;
}
