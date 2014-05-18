#include<iostream>
#include<cstdio>
#include<cstdint>
#include<string>
#include<vector>
using namespace std;


// eval * fist then the + sign
int64_t min(string in)
{
	//cout<<"Inside min: "<<endl; 
	register int i;
	vector<int64_t> v; // the elements of this vector will be added
	int64_t t1= (int64_t)(in[0]-'0');
	for( i=1;i<in.size();i+=2 )
	{
		if( in[i]=='*' )
		{
			t1*=(int64_t)(in[i+1]-'0');
		}
		else if( in[i]=='+' )
		{
			v.push_back(t1);
			t1=(int64_t)(in[i+1]-'0');
		}
	}
	v.push_back(t1);
	t1=0;
	for( i=0;i<v.size() ;i++)
	{
	//	cout<<v[i]<<endl;
		t1+=v[i];
	}
	return t1;
}

// eval + first and then * sign
int64_t max(string in)
{
	//cout<<"Inside max: "<<endl;
	register int i;
	vector<int64_t> v;  // the elements of this vector are multiplied
	int64_t t1=(int64_t)(in[0]-'0');
	for(i=1;i<in.size();i+=2)
	{
		if( in[i]=='+')
		{
			t1+=(int64_t)(in[i+1]-'0');
		}
		else if( in[i]=='*' )
		{
			v.push_back(t1);
			t1=(int64_t)(in[i+1]-'0');
		}
	}
	v.push_back(t1);
	t1=1;
	for(i=0;i<v.size();i++)
	{
	//	cout<<v[i]<<endl;
		t1*=v[i];
	}
	return t1;
}

int main()
{
	int n;
	cin>>n;
	string in;
	while(n--)
	{
		cin>>in;
		cout<<max(in)<<" "<<min(in)<<endl;
	}
	return 0;
}
