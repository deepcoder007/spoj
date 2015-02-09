#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<cstring>
using namespace std;



inline int min(int a,int b)
{
	if( a< b ) return a;
	else return b;
}

inline int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

map<string,int> mp;
map<int,int> rmp;
int m,n;

string tmp;


int main()
{
	register int i,j;
	map<string,int>::iterator it;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if( n==0 && m==0) break;
		mp.clear();
		rmp.clear();
		for(i=0 ; i< n;i++)
		{
			cin>>tmp;
			mp[tmp]++;
		}
		for( it=mp.begin() ; it!=mp.end() ;it++ )
		{
			rmp[it->second] ++;
		}
		for(i=1;i<=n;i++)
			printf("%d\n",rmp[i]);
	}
	return 0;
}



