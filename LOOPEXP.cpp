#include<cstdio>
using namespace std;

double arr[100010];

int main()
{
	arr[1]=1;
	for(int i=2;i<=100010;i+=1)
	{ arr[i]=arr[i-1]+1/(double)i; }
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%.6lf\n",arr[n]);
	}
	return 0;
}


