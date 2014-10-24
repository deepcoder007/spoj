#include<iostream>
using namespace std;
long long int nC2[1000009],sum_i[1000009],alt_sum_i[1000009];
int main()
{
	int i,n;
	long long int sum=0;
	nC2[i]=0; sum_i[i]=0;
	nC2[1]=1; sum_i[1]=1;
	alt_sum_i[0]=0; alt_sum_i[1]=1;
	for(i=2;i<=1000000;i++)
	{
		nC2[i]=i*(i+1)/2;
		sum_i[i]=sum_i[i-1]+nC2[i];
		alt_sum_i[i]=alt_sum_i[i-2]+nC2[i];
	}
	int t; cin>>t;
	while(t--)
	{ cin>>n; sum=sum_i[n]+alt_sum_i[n-1]; cout<<sum<<endl; }
	return 0;
}

	
	
