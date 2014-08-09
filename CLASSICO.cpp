#include<iostream>
#include<climits>
#include<cstdio>
#include<cstdlib>
using namespace std;
// all arrays are 1-ary 


int max(int a,int b)
{	
	if(a>b) return a;
	else    return b;
}

int min(int a,int b)
{
	if( a<b ) return a;
	else return b;
}

int arr[2009];  // the array stores the data 

int tree[10000];  // stores the index of the largest element starting from 1

int n;


void init(int node,int i,int j)  // initialize node between i and j
{
	if(i==j)
	{   tree[node]=i;  }
	else if(i<j)
	{
		int mid=i+ (j-i)/2;
		init(2*node,i,mid);
		init(2*node+1,mid+1,j);
		if( arr[tree[node*2]] > arr[tree[node*2+1]] )
			tree[node]=tree[node*2];
		else tree[node]=tree[node*2+1];
	}
}


// node,i,j are like earlier arguments   l and r are the range of searching
// returns the index of the biggest node
int get_max(int node,int i,int j,int l,int r)
{
	arr[0]=INT_MIN;
	if(l<=i && r>=j) return tree[node];
	else if( r<i || l>j) return 0;  // indicates out of range
	else
	{
		int mid=i+(j-i)/2;
		int left=get_max(node*2,i,mid,l,r);
		int right=get_max(node*2+1,mid+1,j,l,r);
		if(arr[left]>arr[right]) return left;
		else return right;
	}
}

int out[12];
int out_index[12];

void test(int t)  // the count of the test case
{
	cin>>n;
	int i,j;
	int a,b,c;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	if(n<11) {   printf("Case %d: go home!\n",t);return;    }
	else
	{
		init(1,1,n);
		out[0]=0;
		out_index[0]=0;    //boundary case
		int r_limit=n-10;
		for(i=1;i<=11;i++,r_limit++)
		{
			out_index[i]=get_max(1,1,n,out_index[i-1]+1,r_limit);
			out[i]=arr[out_index[i]];
		}
		printf("Case %d: %d %d %d %d %d %d %d %d %d %d %d\n",t,out[1],out[2],out[3],out[4],out[5],out[6],out[7],out[8],out[9],out[10],out[11]);
	}
}

int main()
{
	int t;
	cin>>t;
	int i;
	for(i=1;i<=t;i++)
		test(i);
	return 0;
}








