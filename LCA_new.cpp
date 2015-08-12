#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;


inline int scan()
{
  register int n=0;
  register char c;
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

int t,n,m,q;
int arr[1005];

int main()
{
  register int i,j,k,l;
  register int tmp1,tmp2,count;
  t=scan();
  memset(arr,0,sizeof(arr));
  for( i=1;i<=t;i++)
    {
      n=scan();
      for(j=1;j<=n;j++)   // for all the nodes
	{
	  m=scan(); 
	  while(m--)
	    {
	      k=scan();
	      arr[k]=j;   // k's parent is j
	    }
	}
      q=scan();    // the number of queries
      printf("Case %d:\n",i);
      while(q--)
	{
	  j=scan(); k=scan();
	  stack<int> st1,st2;  // two stacks
	  while(j!=0)
	    {
	      st1.push(j);
	      j=arr[j];
	    }
	  while(k!=0)
	    {
	      st2.push(k);
	      k=arr[k];
	    }
	  count=0;
	  while( !st1.empty() && !st2.empty() && st1.top()==st2.top() )
	    {
	      count=st1.top();
	      st1.pop();
	      st2.pop();
	    }
	  cout<<count<<endl;
	}
    }
  return 0;
}
