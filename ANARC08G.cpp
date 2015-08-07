#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int t,n;
int arr[1009][1009];  // the graph
int score[1009];  // the debt/credit of the nodes

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while(c<'0' || c>'9')
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

int main()
{
  register int i,j;
  int tmp1,tmp2;
  t=1;
  while(1)
    {
      n=scan();
      tmp2=0;
      if(n==0) break;
      for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	  {
	    arr[i][j]=scan();
	    tmp2+=arr[i][j];
	  }
      for(i=1;i<=n;i++)
	{
	  tmp1=0;  // to store the net
	  for(j=1;j<=n;j++)
	    {
	      tmp1+=arr[i][j];
	      tmp1-=arr[j][i];
	    }
	  score[i]=tmp1;
	}
      //now calculate the final
      tmp1=0;
      for(i=1;i<=n;i++)
	if(score[i]>0)
	  tmp1+=score[i];
      printf("%d. %d %d\n",t,tmp2,tmp1);
      t++;
    }
  return 0;
}
