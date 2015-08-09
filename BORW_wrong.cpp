#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

inline int scan()
{
  register int n=0;
  int sgn=1;  
  register char c;
  c=getchar_unlocked();
  while( (c<'0' || c>'9') && c!='-' )
    c=getchar_unlocked();
  if( c=='-' )
    {
      sgn=-1;
      c=getchar_unlocked();
    }
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n*sgn;
}

int arr[210];
int arr2[210];
bool used[210];
int M[210];   // stores the index
int P[210];   // the predecessor/succesor

int main()
{
  register int n,i,j,k,l;
  int L;  // the length of the longest subarray found so far
  int high,mid,low;
  int newL;
  int count=0;  // counts the number of elements used
  while(1)
    {
      cin>>n;
      if( n==-1 ) break;
      for(i=0;i<n;i++)
	arr[i]=scan();

      // now apply the Longest increasing subseq in forward direction
      memset(M,0,sizeof(M));
      memset(P,0,sizeof(P));
      memset(used,0,sizeof(used));
      L=0;
      for( i=0 ; i<n ; i++ )
	{
	  low=1;
	  high=L;
	  while( low<=high )
	    {
	      mid=ceil((low+high)/2);
	      if( arr[M[mid]]<arr[i] )
		low=mid+1;
	      else
		high=mid-1;
	    }
	  newL=low+1;
	  P[i]=M[newL-1];
	  M[newL]=i;

	  if( newL>L ) L=newL;
	}
      // now mark the L elements as used and copy the rest to arr2
      k=M[L];
      for(i=L-1;L>=0;L--) 
	{
	  used[k]=true;
	  k=P[k];
	}
      for(i=0,j=0; i<n; i++ )
	{
	  if( !used[i] )
	    {
	      arr2[j++]=arr[i];
	    }
	}
      // apply that in reverse direction
      count=L;
      L=0; 
      n=(n-count);
      memset(arr2,0,sizeof(arr2));
      memset(M,0,sizeof(M));
      memset(P,0,sizeof(P));
      for( i=0 ; i<n;  i++)
	{
	  if( used[i]==true )
	    continue;
	  low=1;
	  high=L;
	  while( low<=high )
	    {
	      mid=ceil((low+high)/2);
	      if( arr2[M[mid]] > arr2[i] )
		low=mid+1;
	      else
		high=mid-1;
	    }
	  newL=low+1;
	  P[i]=M[newL-1];
	  M[newL]=i;
	  if( newL>L ) L=newL;
	}
      k=M[L];
      for(i=L-1;L>=0;L--)
	{
	  used[k]=true;
	  k=P[k];
	}
      count+=L;
      cout<<(n-count)<<endl;;
    }
  return 0;
}
