#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<algorithm>
using namespace std;
int H[510];   // array to store the health of soldiers
int main()
{
	int t,n,m,d,tmp;
	int i,j;
	cin>>t;
	bool flag;
	while(t--)
	{
		flag=false;     // set flag when not possible
		cin>>n>>m>>d;
		for(i=0;i<n;i++)
			cin>>H[i];   //stores the health of soldiers
		sort(H,H+n);
		j=0;   // pointer to the soldier to be deleted
		for(i=0;i<m;i++)  //iterate over all towers
		{
			while(H[j]<=d) j++;
			if(j>=n)  //i.e. game over,set the flag
			{ flag=true; break; }
			H[j]-=d;  //just reduce it and move to next
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

