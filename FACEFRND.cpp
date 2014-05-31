#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> frnd;
	set<int> frnd2;  //the set of friend of friend
	int n,k;
	int i,j;
	int tmp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		frnd.insert(tmp);
		cin>>j;
		for(k=0;k<j;k++)
		{
			cin>>tmp;
			frnd2.insert(tmp);
		}
	}
	set<int>::iterator it;
	for(it=frnd.begin();it!=frnd.end();it++)
		frnd2.erase(*it);
	cout<<frnd2.size()<<endl;
	return 0;
}


