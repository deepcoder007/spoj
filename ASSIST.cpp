#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


bool mask[5101];


int main()
{
	int i,cur,j,k;
	for(i=0;i<=3000;i++)
		mask[i]=true;    // the digit is available
	cur=1;
	while(cur<3000)
	{
		while(mask[cur]==false)
			cur++;
		j=0;
		for(i=cur+1;i<=3000;i++)
		{
			if(mask[i])
			{
				j++;
				if( j==cur )
				{
					mask[i]=false;
					j=0;
				}
			}
		}
		cur++;
	}
	while(1)
	{
		cin>>i;
		if(i==0) break;

		j=0;
		for(k=1;k<=3000;k++)
		{
			if(mask[k]==true)
			{
				j++;
				if(j==i)
				{
					cout<<k<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
			


	


