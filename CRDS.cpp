// the card arrangement
#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;   //stores the result 

inline void ans()
{
	v.push_back(3) ;   v.push_back(7);
	int ans=7;
	register int i;  //counter
	for( i=3; i<=1000000; i++ ) // iterate over all levels
	{
		ans= (ans+ (2*i)%1000007 + (i-1)%1000007 )%1000007;
		v.push_back(ans);
	}
}

int main()
{
	ans();
	int t;
	scanf("%d",&t);
	int n;
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",v[n-1]);
	}
	return 0;
}
		
