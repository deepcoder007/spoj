#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while( c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9')
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

int t,n;
int arr[100009];  // the list to hold the corridor distance

int main()
{
  register int i,j;
  t=scan();
  long sum,minima,partial_sum ; 
  while(t--)
    {
      sum=0;

      n=scan();
      for(i=0;i<n;i++)
	{
	  arr[i]=scan();
	  sum+=arr[i];
	}
      minima=2*sum;  
      // now search the minima
      partial_sum=0;  // sum of the corridors just before the rejected one
      for(i=0;i<n;i++)   // reject one corridor one by one
	{
	  minima=min( minima, min( partial_sum+sum-arr[i], 2*(sum-arr[i])-partial_sum )) ;
	  partial_sum+=arr[i];
	  //	  cout<<"at i : "<<i<<" minima: "<<minima<<endl;
	}
      cout<<minima<<endl;
    }
  return 0;
}
