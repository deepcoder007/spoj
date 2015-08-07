#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

inline int scan()
{
  register char c;
  register int n=0;
  c=getchar_unlocked();
  while( c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int arr[10009];
int t,n;

int main()
{
  register int i,j;
  t=scan();
  unsigned long long sum;
  while(t--)
    {
      sum=0;
      n=scan();
      for(i=1;i<=n;i++)
	{
	  arr[i]=scan();
	  sum+=2*arr[i]*i-arr[i]*(n+1);
	}
      cout<<sum<<endl;
    }
  return 0;
}
