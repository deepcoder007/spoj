#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


void test()
{
	int i,j,k,l;   // the marking variables
	int matrix[101][101];    
	int coeff[101];
	long long int num,deno;    // the numerator and the denominator
	int sum;
	int s,c;
	scanf("%d%d",&s,&c);
	for(i=0;i<s;i++)
		scanf("%d",&matrix[0][i]);
	// now calculate the difference matrix
	for(i=1;i<s;i++)
	{
		for(j=0;j<(s-i);j++)
		{
			matrix[i][j]=matrix[i-1][j+1]-matrix[i-1][j];
		}
	}
	/*
	cout<<"Now printing the matrix : "<<endl;
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	*/
	for(i=0;i<s;i++)
		coeff[i]=matrix[i][0];
	
	// Now calculate the value of polynomial
	for(i=s+1;i<=(s+c);i++)    // for the following sequence
	{
		sum=coeff[0];  
		num=deno=1;
		l=1;      // the factorial power	
		for(j=1;j<s;j++)    
		{
			num*=(i-j);
			deno*=l;
			l++;
			sum+=(num*coeff[j]/deno);
		}
		cout<<sum<<" ";
	}
	cout<<endl;
}





int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
