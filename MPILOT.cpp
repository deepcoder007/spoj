#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
using namespace std;

template<class T>
inline T MIN(T i,T j)
{
  if( i<j ) return i;
  else return j;
}

nvoid getA(int);
void getC(int);

int n;
int arrC[10009];
int arrA[10009];
int vis[10009];   // to check if this is visited or not
int vis_count;      // the no. of nodes that are visited
int sum;




int main()
{
  register int i,j;
  sum=-1;
  cin>>n;
  memset(vis,0,sizeof(vis));

  return 0;
}
