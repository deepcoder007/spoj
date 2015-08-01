#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
int n,m;
int arr[109];
bool isdeactive[109];

void test()
{
  memset(arr,0,sizeof(int)*105);
  memset(isdeactive,0,sizeof(bool)*105);
  register int i,j;
  register int time=0;   // the total time for our job to be printed
  int deactive_count=0; // the number of deactive numbers
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  i=0;
  bool having_higher=false;
  int curr_pos=0;    // the position of the current element in the array
  while( isdeactive[m]==false ) // while our job is not printed
    {
      having_higher=false;
      for( i=curr_pos+1 ;  i!=curr_pos ;  )
	{
	  if( i == n )
	    {
	      i=0;
	      continue;
	    }
	  if( isdeactive[i]==false && arr[i]>arr[curr_pos] )
	    {
	      having_higher=true;
	    }
	  i++;
	}
      if( having_higher==false) // i.e. print this
	{
	  time++;
	  isdeactive[curr_pos]=true;
	  if( curr_pos==m ) break;
	}
      //shift the curr_pos
      curr_pos++;
      if( curr_pos==n ) curr_pos=0;
      while( isdeactive[curr_pos]!=false ) 
	{
	  curr_pos++;
	  if( curr_pos==n ) curr_pos=0;
	}
    }
  printf("%d\n",time);
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      test();
    }
  return 0;
}
