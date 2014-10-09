#include<iostream>
#include<cstdio>
using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int arr[100009];   // the location of the stress
int diff[100009];    // the difference location of the trees


int main()
{
	int n;	  // stores the number of trees		
	register int i;
	scanf("%d",&n);
	scanf("%d",&arr[0]);	
	for(i=1;i<n;i++)
	{
		scanf("%d",&arr[i]);
		diff[i]=arr[i]-arr[i-1];
	}
	int gcd_all=diff[1];
	for(i=2;i<n;i++)
	{ gcd_all=gcd(gcd_all,diff[i]); }
//	cout<<"GCD : "<<gcd_all<<endl;
	int count=0;
	for( i=1;i<n;i++)
	{
		count+= diff[i]/gcd_all;
		count--;
	}
	printf("%d\n",count);
	return 0;
}
	
