#include<iostream>
#include<cstdio>
using namespace std;

int a[101][501];
int b[101][501];

inline bool max( int a,int b)  //return true if b > a
{ return b>a; }

void test(int budget,int n)  // n is the no. of parties
{
	FILE* ptr=fopen("log.txt","w");
	register int i,j,k;
	int v[n+1];
	int w[n+1];
	//get inputs
	for( i=0;i<n;i++)   //input data
		cin>>w[i+1]>>v[i+1];
	for( i=0 ; i<=budget ; i++ )   //initialize the first trivial row
	{
		b[0][i]=0;
		a[0][i]=0;
	}
	for(i=0;i<=n;i++)
	{
		b[i][0]=0;
		a[i][0]=0;
	}
	for( i=1 ; i<=n ; i++ )   // on the i items 
	{
		for( j=1 ;j <=budget ; j++ )
		{
			if( w[i] >  j ) //the element not accomodated in budget
			{
				b[i][j]=b[i-1][j];
				a[i][j]=a[i-1][j];
			}
			else
			{
				if( max( b[i-1][j], b[i-1][j-w[i]] + v[i] ) ==true )  // i.e. true when new element should be included
				{
					b[i][j]=b[i-1][j-w[i]]+v[i];
					a[i][j]=a[i-1][j-w[i]]+w[i];
				}
				else
				{	b[i][j]=b[i-1][j];a[i][j]=a[i-1][j];  }
			}
		}
	}
	printf("%d %d\n",a[n][budget],b[n][budget]);
	fclose(ptr);
	return;
}


int main()
{
	int a,b;
	while(1)
	{
		cin>>a>>b;
		if( a==0 && b==0 )
			break;
		test(a,b);
	}
	return 0;
}
