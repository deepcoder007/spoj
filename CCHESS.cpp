#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
using namespace std;
// simple logic -> make a graph of 64 nodes and the corresponding edges of moves with weight being the cost of the movement

unsigned int g[65][65];

inline bool in_bound(int i,int j)  // checks if the coordinates are inside the region
{
  if( i<0 || j<0 ) return false;
  if( i>7 || j>7 ) return false;
  return true;
}

inline unsigned int min(unsigned int i,unsigned int j)
{
  if( i<j ) return i;
  else return j;
}

inline void init()
{
  //  memset(g,0,sizeof(g));
  int x_coord[]={ -1,-2,-2,-1,+1,+2,+2,+1 };
  int y_coord[]={ -2,-1,+1,+2,+2,+1,-1,-2 };
  register int i,j,k;
  for(i=0;i<64;i++)
    for(j=0;j<64;j++)
      g[i][j]=INT_MAX;
  for(i=0;i<64;i++)
    g[i][i]=0;
   for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      for( k=0;k<8;k++ )
	{
	  if( in_bound(i+x_coord[k],j+y_coord[k]) )
	    {
	      g[i*8+j][ (i+x_coord[k])*8+(j+y_coord[k]) ] =( (i)*(i+x_coord[k]) + (j)*(j+y_coord[k] ) );
	    }
	}
}

inline void floyd()
{
  register int i,j,k;
  // now apply the floyd warshall
  for(k=0;k<64;k++)
    for(i=0;i<64;i++)
      for(j=0;j<64;j++)
	{
	  if( i==j ) continue;
	  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
  //print the distance
  /*
  for(i=0;i<64;i++)
    {
    for(j=0;j<64;j++)
      {
	cout<<g[i][j]<<" ";
      }
    cout<<endl;
    }
  */
}

int main()
{
  init();
  floyd();
  int a,b,c,d;
  while( scanf("%d%d%d%d",&a,&b,&c,&d )!=EOF )
    {
      cout<<g[a*8+b][c*8+d]<<endl;
    }
  return 0;
}
