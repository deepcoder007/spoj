#include<iostream>
#include<cstdio>
#include<cstdlib>
#define LL long long int 
using namespace std;

int no_of_1;
int get_log(LL n)
{
  int count=0;
  while(n)
    {
      count++;
      if(n&1) no_of_1++;
      n/=2;
    }
  return count-1;
}


int main()
{
  register int i,j;
  LL g,t,a,d;
  LL match;
  LL team;
  int l,pow;
  while(1)
    {
      no_of_1=0;
      scanf("%lld%lld%lld%lld",&g,&t,&a,&d);
      if(g==-1) break;
      match=g*(t*(t-1)/2);
      team=g*a+d;  // the number of teams in the round 2
      l=get_log(team);
      if(no_of_1==1) // i.e. power of 2
	{
	  team=0;
	  pow=l;
	}
      else
	{
	  team=((LL)1<<(l+1))-team;
	  pow=l+1; 
	}
      match+=(((LL)1<<pow)-1);
      printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,match,team);
    }
  return 0;
}
