#include<iostream>
#include<cstdio>
using namespace std;


// returns the vertical steps required 
// facing is true if it is facing the direction it want to go
int vert(int i,bool facing)
{
	int step=0;
	if(facing==false)
	{
		if( i%2==1 )   // i.e. odd number of steps
		{
			step=(i-1)*2+1;
		}
		else
		{
			step=i*2;
		}
	}
	else
	{
		if( i%2==1 )
		{
			step=((i+1)/2)*3 + (i-1)/2 ; 
		}
		else
		{
			step= 2*(i+1);
		}
	}
	return step;
}

int min(int a,int b)
{
	if( a<b) return a;
	else return b;
}

int main()
{
	int t;
	int x,y; int step;
	int k,z;
	cin>>t;
	while(t--)
	{
		step=0;
		cin>>x>>y;
		if( x<0 )
		{
			step=1;
			z=x;
			x=y-1;
			y=-x;
			if(x<0) x=-x;
		}
		k=min(x,y);
		step+=k*2;
		x-=k;
		y-=k;
		if(x==0 && y!=0 ) step+=vert(y,false);
		else if(y==0 && x!=0 ) step+=vert(x,false);
		cout<<step<<endl;
	}
	return 0;
}

			


