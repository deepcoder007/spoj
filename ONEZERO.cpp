#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
// I think this is using chinese remainder theorem somewhere

bool visited[20009];  // for all modulus

struct node
{
	char data[2009];
	int mod;
};

void bfs(int x)   // find multiple of x
{
	memset(visited, 0, sizeof(bool)*20009 );
	queue<node> q;
	node tmp,tmp1;
	strcpy(tmp.data,"1");
	tmp.mod=1%x;
	q.push(tmp);
	while(!q.empty())
	{
		node tmp = q.front(); 
		q.pop();
		if( tmp.mod == 0 )
		{
			printf("%s\n",tmp.data);
			break;
		}
		visited[tmp.mod]=1;
		strcpy(tmp1.data,tmp.data );
		strcat(tmp1.data,"0");
		tmp1.mod = atoi(tmp1.data)%x ;
		if( !visited[tmp1.mod] )
			q.push( tmp1 );
		strcat(tmp.data,"1");
		tmp.mod = atoi(tmp.data)%x ;
		if( !visited[tmp.mod] )
			q.push( tmp );
	}
}
	

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bfs(n);
	}
	return 0;
}
