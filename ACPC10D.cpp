#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;

inline int min(int a,int b)
{
	if( a<b) return a;
	else return b;
}

long int test(int n)   // n stores the no. of numbers
{
	long int a,b,c;
	long int i=0,j=0,k=0;   //stores the current input layer
	long int x=0,y=0,z=0;//stores the cost
	long int x1,y1,z1;   //past values of x,y,z
	cin>>a>>b>>c;
	x=INT_MAX; y=b; z=b+c;
	n--; n--;
	while(n--)
	{
		cin>>i>>j>>k;
		x1=x;y1=y;z1=z;
		x=min(x1,y1)+i;
		y=min(min(x,x1),min(y1,z1))+j;
		z=min(min(y,y1),z1) +k;
	}
	cin>>i>>j>>k;
		x1=x;y1=y;z1=z;
		x=min(x1,y1)+i;
		y=min(min(x,x1),min(y1,z1))+j;
		z=min(min(y,y1),z1) +k;
	return y;
}


int main()
{
	int n;
	cin>>n;
	int i;
	for(i=1;n;i++)
	{
	        printf("%d. %ld\n",i,test(n));
		cin>>n;
	}
	return 0;
}
