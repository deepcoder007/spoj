#include<iostream>
#include<cstdio>
using namespace std;

int max(int a,int b)
{
	if( a>b ) return a;
	else return b;
}

int main()
{
	int a,b,c,d,a1,b1,c1,d1;
	int a2,b2,c2,d2;
	int i,j,k,l;
	int m;   //stores the max no. of items
	while(1)
	{
		cin>>a>>b>>c>>d>>a1>>b1>>c1>>d1;
		if(a==-1 && b==-1 && c==-1 ) break;
		if( a%a1==0 ) m=a/a1;
		else m=(a/a1)+1;
		if( b%b1==0 ) m=max(m,b/b1);
		else m=max(m,(b/b1)+1);
		if( c%c1==0 ) m=max(m,c/c1);
		else m=max(m,(c/c1)+1);
		if( d%d1==0 ) m=max(m,d/d1);
		else m=max(m,(d/d1)+1);
		a2=m*a1-a;
		b2=m*b1-b;
		c2=m*c1-c;
		d2=m*d1-d;
		printf("%d %d %d %d\n",a2,b2,c2,d2);
	}
	return 0;
}




	
