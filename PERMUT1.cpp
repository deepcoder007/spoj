#include<cstdio>
using namespace std;


int arr[15][100];

int main()
{
	int i,j,k,l,n;
	for(i=1;i<=12;i++)
		for(j=0;j<100;j++)
			arr[i][j]=0;
	for(i=1;i<=12;i++)
		arr[i][0]=1;  //i.e. the 0 inversion case
	int tmp;
	for(n=2;n<=12;n++)
	{
		for(k=1;k<100;k++)  //for the number of inversion
		{
			tmp=0;
			for(i=k,j=n;i>=0 && j>0 ; i--,j-- )
			{
				tmp+=arr[n-1][i];
			}
			arr[n][k]=tmp;
		}
	}
	int d;
	scanf("%d",&d);
	while(d--)
	{
		scanf("%d %d",&i,&j);
		printf("%d\n",arr[i][j]);
	}
	return 0;
}

