#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int n,k;

double get(int n,int k)    // no. of getting k in n turns if only moves allowed are 1..6
{
  if( k<1 ) return 0;
  if(n==1 && k>=1 && k<=6 ) return (((double)1)/6);   // the base case
  if(n==1 && (k<1 || k>6 ) )  return 0;
  double out=0;
  for(int i=1;i<=6;i++ ) out+=(get(n-1,k-i)*(((double)1)/6));
  return out;
}


inline void test()
{
  cin>>n>>k;
  cout<<((int)(get(n,k)*100))<<endl;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
    test();
  return 0;
}
