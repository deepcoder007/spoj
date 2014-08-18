#include<iostream>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

// data and count of head will be -1 
struct node
{
	int count;
	node* list[10];
};



class trie
{
public:
	node* head;
	trie()
	{
		head=new node;
		head->count=-1;
		for(int i=0;i<10;i++)
			head->list[i]=NULL;
	}
	void insert(string in)
	{
		int i,j,k;
		node* tmp=head;
		for(i=0 ; i<in.size() ;i++)
		{
			if( tmp->list[in[i]-'0']==NULL ) 
			{
				tmp->list[in[i]-'0']=new node;
				tmp->list[in[i]-'0']->count=1;
			        tmp=tmp->list[in[i]-'0'];
				for(j=0;j<10;j++)
					tmp->list[j]=NULL;
			}
			else
			{
				tmp->list[in[i]-'0']->count++;
				tmp=tmp->list[in[i]-'0'];
			}
		}
	}
	bool exist(string in) //checks if the string is already there
	{
		// true means node is there
		int i,j,k;
		node* tmp=head;
		for(i=0;i<in.size();i++)
		{
			if( tmp->list[in[i]-'0']==NULL)
			{
				return false;
			}
			else
			{
				tmp=tmp->list[in[i]-'0'];
			}
			if(i==(in.size()-1) )
			{
				return true;
			}
		}
	}
};


/*
int main()
{
	string in,out;
	trie t;
	int opt;
	while(1)
	{
		cout<<"Enter option 1.insert, 2.find, 3. exit "<<endl;
		cin>>opt;
		if(opt==3) return 0;
		if(opt==1)
		{
			cin>>in;
			t.insert(in);
		}
		if(opt==2)
		{
			cin>>out;
			cout<<" found/not :" <<t.exist(out)<<endl;
		}
	}
	return 0;
}
*/



void test()
{
	int n;
	cin>>n;
	trie t;
	int i,j;
	string tmp;
	bool ans=true;   // list is consistent initially
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		if( ans )
		{
			if(t.exist(tmp))
			{
				ans=false;
			}
			else
			{
				t.insert(tmp);
			}
		}
	}
	if( ans )
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;
}



int main()
{
	int n;
	cin>>n;
	while(n--)
		test();
	return 0;
}

