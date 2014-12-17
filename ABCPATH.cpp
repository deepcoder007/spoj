#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

int max(int a,int b)
{
	if( a>b) return a;
	else return b;
}
struct pt { int x,y; };

bool visited[55][55];
char arr[55][55];
char maxchar;    // to store the max character reacher till now

inline int test(int x,int y)
{
	queue<pt> q;
	memset(visited,0,sizeof(visited));
	register int i,j;
	for(i=0;i<x;i++)
		scanf("%s",arr[i]);
	
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			if(arr[i][j]=='A') q.push((pt){i,j});
			maxchar='A';
		}
//	cout<<q.size()<< "  SZ"<<endl;

	pt tpt;  // the temporary point
	while(!q.empty())
	{
//		cout<<"HERE : "<<maxchar<<endl;
		tpt=q.front();
		q.pop();
		if(visited[tpt.x][tpt.y]==false)
			visited[tpt.x][tpt.y]=true;
		else continue;
		// now check all the verticals, horizonatals and the diagonals
		if( tpt.x>0 && tpt.y>0  &&  arr[tpt.x-1][tpt.y-1]==(arr[tpt.x][tpt.y]+1) ) 
		{
			maxchar=max(maxchar,arr[tpt.x-1][tpt.y-1]);
			q.push((pt){tpt.x-1,tpt.y-1}); 
		}
		if( tpt.x>0 &&  arr[tpt.x-1][tpt.y]==(arr[tpt.x][tpt.y]+1))
		{
			maxchar=max(maxchar,arr[tpt.x-1][tpt.y]);
			q.push((pt){tpt.x-1,tpt.y}); 
		}
		if( tpt.x>0 && tpt.y<(y-1) && arr[tpt.x-1][tpt.y+1]==(arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar,arr[tpt.x-1][tpt.y+1]);
			q.push((pt){tpt.x-1,tpt.y+1});  
		}
		if( tpt.y<(y-1)  && arr[tpt.x][tpt.y+1] == (arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar,arr[tpt.x][tpt.y+1]);
			q.push((pt){tpt.x,tpt.y+1});  
		}
		if( tpt.x<(x-1) && tpt.y<(y-1)  && arr[tpt.x+1][tpt.y+1] == (arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar,arr[tpt.x+1][tpt.y+1]);
			q.push((pt){tpt.x+1,tpt.y+1}); 
		}
		if( tpt.x<(x-1) && arr[tpt.x+1][tpt.y]==(arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar,arr[tpt.x+1][tpt.y]);
			q.push((pt){tpt.x+1,tpt.y});  
		}
		if( tpt.x<(x-1) && tpt.y>0 && arr[tpt.x+1][tpt.y-1] == (arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar, arr[tpt.x+1][tpt.y-1] );
			q.push((pt){tpt.x+1,tpt.y-1});  
		}
		if( tpt.y>0  && arr[tpt.x][tpt.y-1] == ( arr[tpt.x][tpt.y]+1) )
		{
			maxchar=max(maxchar,arr[tpt.x][tpt.y-1]);
			q.push((pt){tpt.x,tpt.y-1});  
		}
	}
	return (int)(maxchar-'A'+1);
}

int main()
{
	int i; int x,y;
	for(i=1;;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==0 && y==0 ) break;
		printf("Case %d: %d\n",i,test(x,y));
	}
	return 0;
}


