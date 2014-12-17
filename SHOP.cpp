#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

inline int min(int a,int b)
{
	if( a< b) return a;
	else return b;
}

int w,h;
char grid[27][27];
int mintime[27][27];

struct pt
{ int x,y; };

pt tmp1;


int main()
{
	register int i,j,k;
	while(1)
	{
		scanf("%d%d",&w,&h);
		if( w==0 && h==0 ) break;
		for(i=0;i<h;i++) for(j=0;j<w;j++) mintime[i][j]=INT_MAX;
		queue<pt> q;   // the queue for the BFS
		for(i=0;i<h;i++)
			scanf("%s",grid[i]);
		// input complete
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				if(grid[i][j]=='S')
				{
					q.push((pt){i,j});
					mintime[i][j]=0;
					grid[i][j]='0';
					break;
				}
		while(!q.empty())
		{
			tmp1=q.front();
//			cout<<"The element is : "<<tmp1.x << "\t"<<tmp1.y<<endl;
			if(tmp1.x>0 && grid[tmp1.x-1][tmp1.y]!='X' )  // i.e. a normal number or the destination
				if( mintime[tmp1.x-1][tmp1.y] > (mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0') )
				{
					if(grid[tmp1.x-1][tmp1.y]!='D')
					q.push((pt){tmp1.x-1,tmp1.y});
					mintime[tmp1.x-1][tmp1.y]=mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0';
				}
			if(tmp1.x<(h-1) && grid[tmp1.x+1][tmp1.y]!='X' )
				if( mintime[tmp1.x+1][tmp1.y] > (mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0' ) )
				{
					if(grid[tmp1.x+1][tmp1.y]!='D')
					q.push((pt){tmp1.x+1,tmp1.y});
					mintime[tmp1.x+1][tmp1.y]=mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0';
				}
			if(tmp1.y>0 && grid[tmp1.x][tmp1.y-1]!='X' )
				if( mintime[tmp1.x][tmp1.y-1] > (mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0' )) 
				{
					if(grid[tmp1.x][tmp1.y-1]!='D')
					q.push((pt){tmp1.x,tmp1.y-1});
					mintime[tmp1.x][tmp1.y-1]=mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0';
//					cout<<"HERE :"<<tmp1.x<<"  "<<tmp1.y<<"    mintime : "<<mintime[tmp1.x][tmp1.y-1]<<endl;
//					cout<<" mintime original : "<<mintime[tmp1.x][tmp1.y]<<"   grid:  "<<grid[tmp1.x][tmp1.y]<<endl;
				}
			if(tmp1.y<(w-1) && grid[tmp1.x][tmp1.y+1]!='X' )
				if( mintime[tmp1.x][tmp1.y+1] > (mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0' ))
				{
					if(grid[tmp1.x][tmp1.y+1]!='D')
					q.push((pt){tmp1.x,tmp1.y+1});
					mintime[tmp1.x][tmp1.y+1]=mintime[tmp1.x][tmp1.y]+grid[tmp1.x][tmp1.y]-'0';
				}
			q.pop();
		}
		/// DEBUG CODE [START]
/*
		cout<<endl;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
				cout<<mintime[i][j]<<"  ";
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
				cout<<grid[i][j]<<"  ";
			cout<<endl;
		}
		cout<<endl;
		*/
		/// DEBUG CODE [END]
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				if(grid[i][j]=='D')
				{
					printf("%d\n",mintime[i][j]);
					break;
				}

	}
}
	
