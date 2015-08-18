#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

inline int scan()
{
  register int n=0;
  register char c=getchar_unlocked();
  while( c<'0' || c>'9' )
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

inline int max(int i,int j)
{
  if( i>j ) return i;
  else return j;
}

inline int min(int i,int j)
{
  if( i<j ) return i;
  else return j;
}

int main()
{
  int t,n;
  int ch,s,sp, wm;   // wm -> no. of months to wait before firing a worker
  int tmp1,tmp2,tmp3;
  int arr[26];
  int pay,curr;   
  register int i,j;
  t=1;
  while(1)
    {
      n=scan();
      if( n==0 ) return 0;
      ch=scan() ; s=scan(); sp=scan();
      wm = ceil( (double)(ch+sp)/s );
      for(i=0;i<n;i++)
	arr[i]=scan();
      // now start the calculations
      curr=pay=0;
      curr=arr[0];         // current no. of workers we have
      pay=(ch+s)*arr[0];    // you have to hire these many workers at any cost
      for(i=1;i<(n-1);i++)      // consider all the future positions
	{
	  if( arr[i]>curr )    
	    {
	      pay+=(ch*(arr[i]-curr));  // the new workers
	      curr=arr[i];
	      pay+=(s*curr); // the salary at the current time step
	    }
	  else if( arr[i]<curr )      // check if some workers need to be fired
	    {
	      tmp1=0;   // find max of next (wm) months
	      for( j=0; j<wm && (i+j)<n ; j++ )
		{
		  tmp1=max(tmp1,arr[i]);
		}
	      if( tmp1>curr)    // no need to fire workers
		{
		  pay+=(s*curr);
		}
	      else     // fire (curr-tmp1) workers
		{
		  pay+=(sp*(curr-tmp1));
		  curr=tmp1;
		  pay+=(s*curr);
		}
	    }
	  else 
	    {
	      pay+=(s*curr);
	    }
	}
      // for the last n
      if( arr[n-1]>curr )
	{
	  pay+=(ch*(arr[n-1]-curr));
	  curr=arr[n-1];
	  pay+=(s*curr);
	}
      else if( arr[n-1]<curr ) // if req. less then curren level
	{
	  if( s>sp )   // fire the redundant workers
	    {
	      pay+=(sp*(curr-arr[n-1]));
	      curr=arr[n-1];
	      pay+=(s*curr);
	    }
	  else
	    {
	      pay+=(s*curr);
	    }
	}
      else   
	{
	  pay+=(s*curr);
	}
	  

      cout<<"ANS: "<<pay<<endl;
      t++;
    }
  return 0;
}

