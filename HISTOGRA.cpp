#include<iostream>
#include<climits>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n;

int z;
inline int min(int a,int b)
{
	if( a<b ) return a;
	else return b;
}

inline int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int V[100010];
int tree[600000];


// initialize tree for tree node 'node' for indexes b/w l and r
void init_tree(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=l;
		return;
	}
	init_tree(node*2,l,l+(r-l)/2);
	init_tree(node*2+1,l+(r-l)/2+1,r);
	if( V[tree[node*2]] < V[tree[node*2+1]])
		tree[node]=tree[node*2];
	else tree[node]=tree[node*2+1];
}

// start-end : the dimension of the node, l-r: the dimension of query
int return_min(int node,int start,int end,int l,int r)
{
	//cout<<"Return min of: "<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
	cout<<"l:"<<l<<" r: "<<r<<" start: "<<start<<"  end:"<<end<<endl; 
	if(start==l && end==r) return tree[node];
	if(l>end || r<start){ /*cout<<"l:"<<l<<" r: "<<r<<" start: "<<start<<"  end:"<<end<<endl; */ return INT_MAX; }
	int lmax=return_min(node*2,start,start+(end-start)/2,l,start+(end-start)/2);
	int rmax=return_min(node*2+1,start+((end-start)/2)+1,end,start+(end-start)/2+1,r);
	if( V[lmax]<V[rmax]) return lmax;
	else return rmax;
}

int get_max_area(int l,int r)   // maximum area between l and r
{
	int k;
	cin>>k;
	if(l>r) return 0;
	if(l==r) return V[l];
	int min_y=return_min(1,1,n,l,r);
	cout<<"l:"<<l<<"  r:"<<r<<"  pivot:"<<min_y<<endl;
	int left=get_max_area(l,min_y-1);
	int right=get_max_area(min_y+1,r);
	return min_y;
	return max( min_y*(l-r+1), max(left,right));
}


int main()
{
	//z=0;
	cout<<"Number of numbers:"<<endl;
	cin>>n;
	int i;
	cout<<"Enter the numbers:"<<endl;
	for(i=1;i<=n;i++)
		cin>>V[i];
	init_tree(1,1,n);
	for(i=1;i<=10;i++)
		cout<<tree[i]<<endl;
	return 0;
	cout<<"The max area is: "<<get_max_area(1,n)<<endl;
	return 0;
}
	




