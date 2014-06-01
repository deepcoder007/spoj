#include<cstdio>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
using namespace std;




int main()
{
	int n;
        long long arr1[4010],arr2[4010],arr3[4010],arr4[4010];
        map<long long,long long> sum1,sum2;
        set<long long> d1,d2;
	scanf("%d",&n);
	register int i,j;
	for(i=0;i<n;i++)
		scanf("%lld %lld %lld %lld",arr1[i],arr2[i],arr3[i],arr4[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum1[(arr1[i]+arr2[j])]++;
			d1.insert(arr1[i]+arr2[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum2[(arr3[i]+arr4[j])]++;
			d2.insert(arr3[i]+arr4[j]);
		}
	}
	long long sum=0;
	set<long long>::iterator it;
	for(it=d1.begin();it!=d1.end();it++)
	{
		sum+=sum1[*it]*sum2[-(*it)];
	}
	printf("%d\n",sum);
	return 0;
}



	
	



