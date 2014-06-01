#include<iostream>
#include<cstdio>
using namespace std;


inline int min2(int a,int b)  //returns the largest even number < min(a,b) 
{
	int tmp;
	if( a>b) tmp=b;
	else tmp=a;
	if( tmp%2==0 ) return (tmp-2);
	else return (tmp-1);
}

inline void test()
{
	register int N,M;
	scanf("%d %d",&N,&M);
	if(N>5 && M>5 )
	{   int k=min2(N,M);
		N-=k ;  M-=k;  }
	int x1,x2,y1,y2;
	x1=y1=1;
	x2=M;y2=N;
	register int dir=0;  // 0=right,1=down,2=left,3=up
	while( x1<=x2 && y1<=y2 )
	{
		if(dir==0) {  y1++; }
		else if(dir==1) { x2--; }
		else if(dir==2) { y2--; }
		else if(dir==3) { x1++; }
		dir++; dir=dir%4;
	}
	if( dir==0 ) printf("U\n"); 
	else if(dir==1) printf("R\n");
	else if(dir==2) printf("D\n");
	else if(dir==3) printf("L\n");
	return ;
}


int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
		test();
	return 0;
}
