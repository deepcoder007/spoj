#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char A[2010];
char B[2010];

int m[2010][2010];

inline int min( int a,int b, int c)
{
	if( a>=b && a>=c)
		return a;
	else if( b>=a && b>=c )
		return b;
	else  return c;
}

void test()
{
	cin>>A>>B;
	int lA=strlen(A), lB=strlen(B);
	cout<<"SIZE:"<<lA<<lB<<endl;
	register int i,j,k;
	for( i=0;i<=lB;i++)
	{
		m[0][i]=i;
	}
	for( i=0;i<=lA;i++)
	{
		m[i][0]=i;
	}
	for( i=1;i<=lA ; i++)
	{
		for( j=1 ; j <= lB; j++)
		{
			if( A[i-1]==B[j-1] )  //i and j th character match
			{
				m[i][j]=m[i-1][j-1]+1;
			}
			else
			{
				m[i][j]=min(m[i-1][j-1],m[i-1][j],m[i][j-1])+1;
			}
		}
	}
	cout<<m[lA][lB]<<endl;
	return ;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
		test();
	return 0;
}
