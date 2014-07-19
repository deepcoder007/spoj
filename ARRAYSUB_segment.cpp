#include<iostream>
#include<cstdio>
using namespace std;

int max(int a,int b)
{
	if( a>b) return a;
	else return b;
}

//1-ary array
int arr[1000009];
int segment[5000000];

void init(int i,int l,int r,int* arr)
{
	if(l==r)
	{
		segment[i]=arr[l];
	}
	else
	{
		init(i*2,l,(l+r)/2,arr);
		init(i*2+1,(l+r)/2 +1,r,arr);
		segment[i]=max(segment[2*i],segment[2*i+1]);
	}
}

int query(int k,int l,int r, int i,int j)
{
	if( j<l || i>r ) return 0;  //out of range case
	else if( i<=l && j>=r )
		return segment[k];
	else
		return max( query(2*k,l,(l+r)/2,i,j), query(2*k+1,(l+r)/2+1,r,i,j) );
}



int main() {
    int N;
    scanf( "%d", &N );
    int i;
    for ( i = 1; i <= N; ++i ) {
        scanf( "%d", arr + i );
    }
    init( 1, 1, N, arr );
    int k;
    scanf( "%d", &k );
    for ( i = 1; i + k - 1 <= N; ++i ) {
        printf( "%d ", query( 1, 1, N, i, i + k - 1 ) );
    }
    printf( "\n" );
    return 0;
}
