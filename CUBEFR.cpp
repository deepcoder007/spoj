#include<iostream>
#include<cstdio>
#include<map>
#include<cstdlib>
using namespace std;


bool grid[1000009];   // the grid to tell if the number is free or not
//map<int,int> pos;    // to store the position of the free numbers
int pos[1000009];


int main()
{
	int i,j,k,l,m,n;
	for(i=1;i<=1000000;i++)
		grid[i]=true;     // initialially all are free
	for(i=2;i<=100;i++)
	{
		j=i*i*i;
		for(k=1;k*j<=1000000;k++)
		{ grid[k*j]=false; }
	}
	for(i=1,j=1;i<=1000000;i++)
	{
		if(grid[i])  // if it is free
			pos[i]=j++;
	}
	int t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)   // for all test cases
	{
		scanf("%d",&j);
		if(grid[j])
			printf("Case %d: %d\n",i,pos[j]);
		else
			printf("Case %d: Not Cube Free\n",i);
		fflush(stdout);
	}
	return 0;
}

