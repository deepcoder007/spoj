#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
// solved using the segment tree

struct data
{
	int n1;  // stores the highest number
	int n2;  // stores the second highest number
};

data T[400000];   // the tree to store the data
int A[100000];    // the original array

inline int max(int a,int b)
{
	if( a>b) return a;
	else return b;
}


void init(int n,int l,int r)   // init the tree at node n from left l to right r
{
	if(l>r) return ;
	if(l==r)
	{
		T[n].n1=A[l]; T[n].n2=0;
		return ;
	}
	int mid=l+(r-l)/2;
	init(n*2,l,mid);      // left subtree
	init(n*2+1,mid+1,r);   // right subtree
	if( T[n*2].n1 >= T[n*2+1].n1 )
	{
		T[n].n1=T[n*2].n1;
		if( T[n*2].n2 >=T[n*2+1].n1)
			T[n].n2=T[n*2].n2;
		else
			T[n].n2=T[n*2+1].n1;
	}
	else
	{
		T[n].n1=T[n*2+1].n1;
		if( T[n*2].n1 >= T[n*2+1].n2 )
			T[n].n2=T[n*2].n1;
		else
			T[n].n2=T[n*2].n2;
	}
}


// get the highest 2 numbers in the given range
data query(int n,int l,int r,int x,int y )   // get the highest numbers in the range x and y
{
	if(y<l || x>r ) return (data){0,0};
	if(x<=l && y>=r ) return T[n];
	int mid=l+(r-l)/2;
	data d1=query(n*2,l,mid,x,y);    
	data d2=query(n*2+1,mid+1,r,x,y);
	data tmp;
	if(d1.n1 >= d2.n1 )
	{
		tmp.n1=d1.n1;
		if( d1.n2 >= d2.n1 )
			tmp.n2=d1.n2;
		else
			tmp.n2=d2.n1;
	}
	else
	{
		tmp.n1=d2.n1;
		if(d1.n1 >= d2.n2 )
			tmp.n2=d1.n1;
		else
			tmp.n2=d2.n2;
	}
	return tmp;
}

void update(int n,int l,int r,int i,int x)   // update the position of element i to x
{
	if( i<l ||  i>r ) return;
	if(i==l && l==r ) {   T[n].n1=x; return ; }
	int mid=l+(r-l)/2;
	update(n*2,l,mid,i,x);
	update(n*2+1,mid+1,r,i,x);
	if( T[n*2].n1 >= T[n*2+1].n1 )
	{
		T[n].n1=T[n*2].n1;
		if( T[n*2].n2 >=T[n*2+1].n1)
			T[n].n2=T[n*2].n2;
		else
			T[n].n2=T[n*2+1].n1;
	}
	else
	{
		T[n].n1=T[n*2+1].n1;
		if( T[n*2].n1 >= T[n*2+1].n2 )
			T[n].n2=T[n*2].n1;
		else
			T[n].n2=T[n*2].n2;
	}
}


int main()
{
	int n;
	register int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{ scanf("%d",&A[i]); }
	init(1,0,n-1);
	int q;
	scanf("%d",&q);
	char ch;int x,y;
	data tmp;
	scanf("%d\n",&q);
	while(q--)
	{
		cin>>ch>>x>>y;
		if(ch=='Q')
		{
			tmp=query(1,0,n-1,x-1,y-1);
			cout<<tmp.n1+tmp.n2<<endl;
		}
		else
		{
			update(1,0,n-1,x-1,y);
		}
	}
	return 0;
}
			












