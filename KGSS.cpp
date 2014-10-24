#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct data
{
	int n1;
	int n2;
};

int arr[100000];
data T[500000];

void init(int n,int a,int b)    //initialize the segment tree
{
	if(a==b)
	{	T[n].n1=arr[a]; T[n].n2=0 ; return ; }
	int mid=a+(b-a)/2;
	init(n*2,a,mid);
	init(n*2+1,mid+1,b);
	if( T[n*2].n1>=T[n*2+1].n1 )
	{
		T[n].n1=T[n*2].n1;
		if( T[n*2].n2 >=T[n*2+1].n1 )
			T[n].n2=T[n*2].n2;
		else
			T[n].n2=T[n*2+1].n1;
	}
	else
	{
		T[n].n1=T[n*2+1].n1;
		if( T[n*2+1].n2 >= T[n*2].n1 )
			T[n].n2=T[n*2+1].n2;
		else
			T[n].n2=T[n*2].n1;
	}
}

void update(int n,int l,int r,int i,int x)
{
//	cout<<"UPDATE ENTERED"<<endl;
	if(i>r || i<l ) return;
	if(l==r && i==l) { T[n].n1=x; return; }
	int mid=l+(r-l)/2;
	if( i <=mid)
	update(n*2,l,mid,i,x);
	else
	update(n*2+1,mid+1,r,i,x);
	if( T[n*2].n1>=T[n*2+1].n1 )
	{
		T[n].n1=T[n*2].n1;
		if( T[n*2].n2 >=T[n*2+1].n1 )
			T[n].n2=T[n*2].n2;
		else
			T[n].n2=T[n*2+1].n1;
	}
	else
	{
		T[n].n1=T[n*2+1].n1;
		if( T[n*2+1].n2 >= T[n*2].n1 )
			T[n].n2=T[n*2+1].n2;
		else
			T[n].n2=T[n*2].n1;
	}
}

int mx(int n,int l,int r,int x,int y)
{
	if(x>r || y<l ) return 0;
	if( x<=l && y>=r ) return T[n].n1;
	int mid=l+(r-l)/2;
	int m1,m2,m3;
	m1=mx(n*2,l,mid,x,y);
	m2=mx(n*2+1,mid+1,r,x,y);
	return (m1>m2)?m1:m2;
}

int max(int a,int b,int c)
{
	if( a>=b && a>=c ) return a;
	else if( b>=c && b>=a ) return b;
	else return c;
}

int query(int n,int l,int r,int x,int y) // find max dual sum between the range x and y
{
//	cout<<"QUERY ENTERED"<<endl;
//	cout<<"range : "<< l <<" "<<r<<" at n = "<<n<<endl;
	//getchar();
	if(x>r || y<l ){ return 0; }
	if( x==l && l==r ) return T[n].n1+T[n].n2;
	else if( l==r && x!=l ) return 0;
	if( x==y ) return 0;
	int mid=l+(r-l)/2;
	int s1,s2,m1,m2;
	s1=query(n*2,l,mid,x,y);
	s2=query(n*2+1,mid+1,r,x,y);
//	cout<<"REC Query done"<<endl;
	m1=mx(n*2,l,mid,x,y);
	m2=mx(n*x+1,mid+1,r,x,y);
//	cout<<"QUERY EXIT"<<endl;
	return max(s1,s2,m1+m2);
}

int main()
{
	int n;
	scanf("%d",&n);
	register int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	init(1,0,n-1);
	//cout<<"segment tree initialized"<<endl;
	int q;
	char ch;
	int a,b;
	scanf("%d",&q);
	//cout<<"START q queries"<<endl;
	for(i=0;i<q;i++ )
	{
		cout<<"QUERY LOOP"<<endl;
		scanf("%c%d%d\n",&ch,&a,&b);
//		scanf("%d %d",&a,&b);
		if( ch=='Q')  // query 
		{ printf("%d\n",query(1,0,n-1,a-1,b-1)); }
		else
		{ update(1,0,n-1,a,b); }
	}
	return 0;
}








