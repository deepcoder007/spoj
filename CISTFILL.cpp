#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

// use binary search logic -> its damn simple question

inline int scan()
{
  register int n=0;
  register char c;
  c=getchar_unlocked();
  while( c<'0' || c>'9' )
    c=getchar_unlocked();
  while( c>='0' && c<='9' )
    {
      n=n*10+c-'0';
      c=getchar_unlocked();
    }
  return n;
}

struct comparison   // the structure used for comparison
{
  int idx ;    // the index in the original array
  int val  ;   // the value to be compared
  bool operator < ( const comparison& s ) const
  {
    return val < s.val;
  }
};

int t,n;
int tmp1,tmp2,tmp3,tmp4;
int bottom[50005];
int top[50005];
int wd[50005];    // i.e. the width*depth
comparison b_sort[50005];   // the objects sorted according to bottomline

// returns volume at the height
inline float get_volume(float h)   

inline void test()
{
  n=scan();
  register int i,j;
  for(i=0;i<n;i++)
    {
      tmp1=scan(); tmp2=scan(); tmp3=scan(); tmp4=scan();
      bottom[i]=tmp1;
      top[i]=tmp1+tmp2;
      wd[i]=tmp3*tmp4;
      b_sort[i].idx=i;
      b_sort[i].val=tmp1;   
    }
  sort(b_sort,b_sort+n);  // sort according to bottom


}

int main()
{
  t=scan();
  while(t--)
    test();
  return 0;
}
  
