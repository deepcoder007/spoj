#include<iostream>
#include<cstdio>
using namespace std;

int k,l,m;
char arr[1000005];

bool win(int n)
{
	if(n<=0 ) return true;
		if( arr[n]==0) 	return false;
		else return true;
}

bool win2(int n)
{
	if( n<=0) return true;
	if( (n-10)>1 ) 
	{
		if( arr[n-1] || arr[n-k] || arr[n-l] )
		return false;
		else return true;
	}
	if(win2(n-1) || win2(n-k) || win2(n-l) )
	{  arr[n]=0;  return false; }
	else
	{  arr[n]=1;  return true;  }
}
	



void test()
{
	int n;
	scanf("%d",&n);
	if(arr[n])
	{	printf("B");  	}
	else
	{	printf("A");    }
}


int main()
{
	register int i;
	scanf("%d %d %d",&k,&l,&m);
	for(i=1;i<=1000000;i++)
	{	
//		printf (" %d \n",i);
		arr[i]=win2(i)?1:0;
	}
	while(m--)
	{
		test();
	}
	printf("\n");
	return 0;
}
