#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	int i,n,j,k;
        i=1;
	string in;
	int ans;
	int mark;
	while(true)
	{
		ans=0;  // the number of inversions
		mark=0;  // count of no. of open brackets
		cin>>in;
		if( in[0]=='-' ) break;
		for(j=0;j<in.size();j++)  // over all the iterations
		{
			if( in[j]=='}' && mark==0 )   //an inversion occurs
			{
				ans++;
				mark++;
			}
			else if( in[j]=='}' )
				mark--;
			else mark++;
		}
		ans+=mark/2;
		printf("%d. %d\n",i++,ans);
	}
	return 0;
}

