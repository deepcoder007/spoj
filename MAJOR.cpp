#include<cstdio>
#include<map>
#include<set>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	int n,i,j;
	map<int,int> count;
	set<int> data;
	set<int>::iterator it;
	int tmp;
	bool flag;
	while(t--)
	{
		flag=false;
		data.clear();
		count.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			count[tmp]++;
			data.insert(tmp);
		}
		n/=2;
		for(it=data.begin();it!=data.end();it++)
		{
			if( count[*it]>n )
			{
				flag=true;
				tmp=*it;
			}
		}
		if(flag) { printf("YES %d\n",tmp); }
		else { printf("NO\n"); }
	}
	return 0;
}



		
