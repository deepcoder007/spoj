#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

// true means prime
int sieve1[100009];   // the first list to hold the list of factors to be evaluated
long long int sieve2[100009];  // the second list containing the list in the sieve
long long int m,n;
long long int i,j,k;

void test()
{
	scanf("%Ld%Ld",&m,&n); // the range of numbers
	// first initialize the sieve2  to all prime
	if(m<=1) m=2;
	for( i=m;i<=n;i++)
	{
		sieve2[i-m]=true;
	}
	for( i=2;i<=100000 && i*i<=n && i<m ;i++ )
	{
		if( sieve1[i] )    // if the number is prime
		{
//			cout<<"Checking for prime p = "<<i<<endl;
			j= n/i;
			j=j*i;  // the last number in range which is multiple of i
			for(; j>=m; j-=i )
				sieve2[j-m]=false ;  // mark it composite
		}
	}
//	cout<<"Now starting the second phase "<<endl;
	if( m < 100000 )  
	{
		for(i=m;i*i<=n; i++)
		{
			if( sieve2[i-m] )
			{
//				cout<<"THe prime p = "<<i<<endl;
				for(j=i*i ; j<=n; j+=i )
					sieve2[j-m]=false;
			}
		}
	}
				
	// now print all the numbers
	for( i=m;i<=n;i++ )
	{
		if( sieve2[i-m] )
			printf("%Ld\n",i);
	}
	printf("\n");
}

int main()
{
	long long  int i,j;
	char c;
	// make the sieve 1
	sieve1[1]=false;  
	for( i=2;i<=100000;i++ ) // initialize the values
		sieve1[i]=true;
	for( i=2;i<=100000;i++ )
	{
		if(sieve1[i])  // if the current number is prime
		{
			for( j=i*i;j<=100000; j+=i )
			{
				sieve1[j]=false ; // mark it composite
			}
		}
	}
	// THe prime list is working fine
	int t;
//	cout<<"Enter the number of test cases"<<endl;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
