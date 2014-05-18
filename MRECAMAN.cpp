// the card arrangement
#include<cstdio>
#include<vector>
#include<set>
#include<iostream>
using namespace std;

vector<int> v;   //stores the result 
set<int> s;

inline void ans()
{
	v.push_back(0);
	int ans=0;
	register int i;  //counter
	for( i=1; i<=500000; i++ ) // iterate over all levels
	{
		if( (ans-i)>0 && s.find(ans-i)==s.end() ) { ans=ans-i;  }
		else { ans=ans+i;  }
		v.push_back(ans);
		s.insert(ans);
	}
}

int main()
{
	ans();
	int n;
	scanf("%d",&n);
	while(n!=-1 )
	{
		printf("%d\n",v[n]);
	        scanf("%d",&n);
	}
	/*
	for ( int i=0;i<20;i++)
		cout<<v[i]<<endl;
		*/
	return 0;
}
		
