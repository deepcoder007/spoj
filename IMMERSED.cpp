#include<iostream>
//#include<cstdint>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

inline void test()
{
	long double P;
	int c;
	long double low=1.0,high=14.0;   // the highest and lowest value of N respectively
	long double mid;
	cin>>P>>c;
	// now start the binary search
	while( abs(low-high)>0.0000001 )
	{
		mid=low+(high-low)/2;
		if( abs(log(P)-(c*mid+1)*log(mid))<0.000001 )
		{
		//	cout<<mid<<endl;
			printf("%.6Lf\n",mid);
			return ;
		}
		if( log(P) > (c*mid+1)*log(mid) )
		{ low=mid; }
		else high=mid;
	}
	printf("%.6Lf\n",mid);
//	cout<<mid<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
