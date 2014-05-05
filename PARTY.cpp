#include<iostream>
#include<cstdio>
using namespace std;

inline bool max( int a,int b)  //return true if b > a
{ return b>a; }

void test(int budget,int n)  // n is the no. of parties
{
	FILE* ptr=fopen("log.txt","w");
	register int i,j,k;
	int v[n+1];
	int w[n+1];
	//get inputs
	for( i=0;i<n;i++)
		cin>>w[i+1]>>v[i+1];
	int* b[n+1];    //stores the maximum for corresponding coordinates
	for(i=0;i<=n;i++)
		b[i]=new int[budget+1];
	for( i=0 ; i<=budget ; i++ )   //initialize the first trivial row
		b[0][i]=0;
	for( i=1 ; i<=n ; i++ )
	{
		for( j=1 ;j <=budget ; j++ )
		{
			if( w[i] >  j ) //the element not accomodated in budget
			{
				b[i][j]=b[i-1][j];
			}
			else
			{
				if( max( b[i-1][j], b[i][j-w[i]] + v[i] ) ==true )  // i.e. true when new element should be included
				{
					b[i][j]=b[i][j-w[i]]+v[i];
					if( b[i][j]>100 )
					{
					cout<<"Element included at: "<<i<<" "<<j<<" "<<b[i][j]<<endl;
					fprintf(ptr,"AT : %d %d %d",i,j,b[i][j]);
					}
				}
				else
				{	b[i][j]=b[i-1][j];  }
			}
		}
	}
	cout<<"Max fun: "<<b[n][budget]<<endl;
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
