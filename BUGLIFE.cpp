#include<iostream>
#include<unordered_set>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
using namespace std;


set<int> arr[2001];

bool test()
{
	int n,m;  // n = no. of bugs , m = no. of interactions
	cin>>n>>m;
	int i,j,k;
	unordered_set<int> left;
	for(i=1;i<=n;i++)
	{
		arr[i].clear();
		left.insert(i);
	}
	while(m--)
	{
		cin>>i>>j;
		arr[i].insert(j);
		arr[j].insert(i);
	}
	//cout<<"The graph is initialized:"<<endl;
	set<int> white;
	set<int> black;
	queue<int> q1,q2;  //q1=white, q2=black
	set<int>::iterator it;
	bool tr=true;
	int base;
	//int tmp,tmp2;
	// now start processing
	while(left.size()!=0)
	{
		base=*left.begin();
		white.insert(base);
		left.erase(base);
		q1.push(base);   //push the first element
	//	cout<<"Base ele: "<<base<<endl;
//		cin>>k;
		
		while(!q1.empty() || !q2.empty())
		{
	//		cout<<"Size of white queue :"<<q1.size()<<endl;
//			cin>>k;
			while(!q1.empty())   // there are white elements
			{
	//			cout<<"Processing (white) : "<<q1.front()<<endl;
				it=arr[q1.front()].begin();
				for(;it!=arr[q1.front()].end();it++)  //over all the links of q1.front() 
				{
					if( white.find(*it)!=white.end() )  //i.e. the element is in white
					{
						tr=false; //invalid situation
						break;
					}
					else if( black.find(*it)==black.end() )
					{
						black.insert(*it);
						q2.push(*it);
						left.erase(*it);
					}
				}
				q1.pop();
			}
	//		cout<<"Size of black queue :"<<q2.size()<<endl;
		//	cin>>k;
			while(!q2.empty())
			{
	//			cout<<"Processing (black) : "<<q2.front()<<endl;
				it=arr[q2.front()].begin();
				for(;it!=arr[q2.front()].end();it++)
				{
					if( black.find(*it)!=black.end())
					{
						tr=false;
						break;
					}
					else if(white.find(*it)==white.end())
					{
						white.insert(*it);
						q1.push(*it);
						left.erase(*it);
					}
				}
				q2.pop();
			}
		}
	}
	return tr;
}

int main()
{
	int n;
	cin>>n;
	int i;
	bool tk;
	for(i=1;i<=n;i++)
	{
		tk=test();
		cout<<"Scenario #"<<i<<":"<<endl;
		if(tk)
			cout<<"No suspicious bugs found!"<<endl;
		else 
			cout<<"Suspicious bugs found!"<<endl;
	}
	return 0;
}
