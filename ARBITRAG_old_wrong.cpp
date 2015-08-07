#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
// use a DFS/BFS based approach to find arbitrage

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

struct exchange   // a structure to be pushed at the end of the 
{
  int curr_idx;   // to store the currency index;
  float rate;     // to give the cumulative exchange rate
};

exchange te;  // temporary exchange

bool curr_mark[35]; // to mark the various currencies as visited

int t,n;
map<string,int> m;  // mapping from currency name to the index
float g[35][35];
string t_str,t_str_2,t_str_3;
int tmp1,tmp2,tmp3;
float ft1,ft2;  // float tmp variables
int main()
{
  register int i,j;
  int count=1;  // to count the test case number
  while(1)
    {
      cout<<"\n\nStart the test case: "<<endl;
      bool arbitrage=false;
      m.clear();
      t=scan();   // the number of nodes
      if( t==0 ) break; 
      for(i=0;i<t;i++)
	{
	  cin>>t_str;
	  m[t_str]=i;
	  cout<<t_str<<"  :  "<<i<<endl;
	}
      memset(g,0,sizeof(int)*35*35);
      n=scan();  // the number of rules  
      for(i=0;i<n;i++)
	{
	  cin>>t_str_2>>ft1>>t_str_3;
	  g[m[t_str_2]][m[t_str_3]]=ft1;
	  //	  g[m[t_str_3]][m[t_str_2]]=1/ft1;
	}
      // now start the bfs accorss all the nodes
      for(i=0;i<t && arbitrage==false;i++)   // for each node-> start a dfs
	{
	  cout<<"For currency: "<<i<<endl;
	  queue<exchange> qt;   // to hold the queue for the dfs
	  memset(curr_mark,0,sizeof(bool)*35);

	  // insert all the nodes attached to i into queue
	  for(j=0;j<t;j++)
	    {
	      if( g[i][j]!=0 ) // i.e. exchange exists
		{
		  qt.push((exchange){j,g[i][j]});
		  curr_mark[j]=true; // mark these nodes as visited;
		}
	    }
	  while(!qt.empty() && arbitrage==false )
	    {
	      te=qt.front();
	      cout<<"  curr pop : "<<te.curr_idx<<endl;
	      qt.pop();
	      for(j=0;j<t;j++)
		{
		  if(g[te.curr_idx][j]!=0 )   // if there is a link
		    {
		      if( j==i && abs((te.rate*g[te.curr_idx][i])-1)>0.01 )  // an arbritrage
			{
			  arbitrage=true;
			  break;
			}
		      else if( j!=i && curr_mark[j]==false ) 
			{
			  qt.push((exchange){j,te.rate*g[te.curr_idx][j]});
			  curr_mark[j]=true;
			}
      		    }
		}
	    }
	}		  
      if(arbitrage)	
	printf("Case %d: Yes\n",count++);
      else
	printf("Case %d: No\n", count++);
    }
  return 0;
}


