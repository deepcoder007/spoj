#include<iostream>
#include<cstdio>
using namespace std;


inline void test()
{
	register int N,M;
	cin>>N>>M;
	register int x1,x2,y1,y2;
	x1=y1=1;
	x2=M;y2=N;
	register int dir=0;  // 0=right,1=down,2=left,3=up
	while( x1<=x2 && y1<=y2 )
	{
		if(dir==0) {  y1++; }
		else if(dir==1) { x2--; }
		else if(dir==2) { y2--; }
		else if(dir==3) { x1++; }
		else cout<<"ERROR"<<endl;
		dir++; dir=dir%4;
	}
	if( dir==0 ) cout<<"U"<<endl;
	else if(dir==1) cout<<"R"<<endl;
	else if(dir==2) cout<<"D"<<endl;
	else if(dir==3) cout<<"L"<<endl;
	return ;
}


int main()
{
	int n;
	cin>>n;
	while(n--)
		test();
	return 0;
}
