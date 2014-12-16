#include<iostream>
#include<cstdio>
using namespace std;

int x[1000009];
int y[1000009];
int n;

long double Cx,Cy;
long double A;
long long int tmp;

inline void test()
{
	scanf("%d",&n);
	register int i,j;
	for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[n]=x[0];y[n]=y[0];
	A=0;Cx=Cy=0;
	for(i=0;i<n;i++)
	{
		A+=(x[i]*y[i+1]-x[i+1]*y[i]);
		Cx+=((x[i]+x[i+1])*(x[i]*y[i+1]-x[i+1]*y[i]));
		Cy+=((y[i]+y[i+1])*(x[i]*y[i+1]-x[i+1]*y[i]));
	}
	A/=2;
	Cx/=6*A;
	Cy/=6*A;
	tmp=Cx*1000;
	if(tmp%10>=5) tmp+=(10-tmp%10);
	else tmp-=(tmp%10);
	Cx=tmp/1000;
	tmp=Cy*1000;
	if(tmp%10>=5) tmp+=(10-tmp%10);
	else tmp-=(tmp%10);
	Cy=tmp/1000;
	printf("%.2Lf %.2Lf\n",Cx,Cy);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
