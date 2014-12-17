#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;


int mxmatrix[3][1001][1001];  // 0= Air, 1=Water, 2=Fire, 


int h,a;   // the health and armour
int t;

inline int max(int a,int b,int c)
{
	if( a>=b && a>=c) return a;
	else if( b>=a && b>=c ) return b;
	else return c;
}

int maxtime(int x,int y,int c)   // max-time if health=x,armor=y and  c as given code max matrix
{
//	cout<<"CALLED MAXTIME : "<<x<<"  "<<y<<"  "<<c<<endl;
	if( x<=0 || y<=0 ) return 0;
	if(mxmatrix[c][x][y]!=-1) return mxmatrix[c][x][y];
	int x1,y1,x2,y2;
	if(c==0)   // i.e. current is Air
	{
		x1=x-5;    y1=y-10;
		x2=x-20;   y2=y+5;
		if( maxtime(x1,y1,1)>=maxtime(x2,y2,2) ) { mxmatrix[0][x][y]=maxtime(x1,y1,1)+1; }
		else { mxmatrix[0][x][y]=maxtime(x2,y2,2)+1; }
		return mxmatrix[0][x][y];
	}
	else if(c==1)
	{
		x1=x+3;  y1=y+2;
		x2=x-20;  y2=y+5;
		if( maxtime(x1,y1,0) >= maxtime(x2,y2,2) ) { mxmatrix[1][x][y]=maxtime(x1,y1,0)+1; }
		else { mxmatrix[1][x][y]=maxtime(x2,y2,2)+1; }
		return mxmatrix[1][x][y];
	}
	else
	{
		x1=x+3; y1=y+2;
		x2=x-5; y2=y-10;
		if( maxtime(x1,y1,0) >= maxtime(x2,y2,1) ) { mxmatrix[2][x][y]=maxtime(x1,y1,0)+1; }
		else {  mxmatrix[2][x][y]=maxtime(x2,y2,1)+1;  }
		return mxmatrix[2][x][y];
	}
}




inline void test()
{
	memset(mxmatrix,-1,sizeof(mxmatrix));
	scanf("%d%d",&h,&a);
	
	printf("%d\n",max(maxtime(h,a,0),maxtime(h,a,1),maxtime(h,a,2))-1);
}

int main()
{
	scanf("%d",&t);
	while(t--)
		test();
	return 0;
}
